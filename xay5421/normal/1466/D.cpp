// author: xay5421
// created: Wed Dec 30 22:54:42 2020
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
const int N=200005;
int T,n,a[N],ans[N];
int pp,lnk[N],nxt[N*2],to[N*2];
void ae(int k1,int k2){to[++pp]=k2,nxt[pp]=lnk[k1],lnk[k1]=pp;}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]),lnk[i]=0;
		pp=0;
		rep(i,1,n-1){
			int k1,k2;
			rd(k1),rd(k2);
			ae(k1,k2),ae(k2,k1);
		}
		ans[0]=0;
		rep(i,1,n)ans[0]+=a[i];
		vector<int>t;
		rep(i,1,n)for(int j=nxt[lnk[i]];j;j=nxt[j])t.push_back(a[i]);
		sort(t.rbegin(),t.rend());
		rep(i,0,SZ(t)-1){
			ans[i+1]=ans[i]+t[i];
		}
		rep(i,0,n-2)pt(ans[i],' ');
		puts("");
	}
	return 0;
}