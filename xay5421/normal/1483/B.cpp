// author: xay5421
// created: Sun Mar 21 21:34:41 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VII;
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=100005;
int T,n,a[N],pre[N],nxt[N];
set<int>S;
void del(int x){
	S.erase(x);
	pre[nxt[x]]=pre[x];
	nxt[pre[x]]=nxt[x];
	S.insert(pre[x]);
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]),pre[i]=i-1,nxt[i]=i+1;
		pre[1]=n,nxt[n]=1;
		S.clear();
		rep(i,1,n)if(__gcd(a[i],a[nxt[i]])==1)S.insert(i);
		int cur=1;
		vector<int>ans;
		while(SZ(S)){
			auto it=S.lower_bound(cur);
			if(it==S.end())it=S.begin();
			int i=*it;
			S.erase(it);
			if(__gcd(a[i],a[nxt[i]])!=1)continue;
			ans.push_back(nxt[i]);
			if(nxt[i]==i)break;
			del(nxt[i]);
			cur=nxt[i];
		}
		pt(SZ(ans),' ');
		for(int x:ans)pt(x,' ');
		puts("");
	}
	return 0;
}