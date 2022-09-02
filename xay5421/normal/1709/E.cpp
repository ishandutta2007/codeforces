#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=200005;
int n,a[N];
vector<int>e[N];
set<int>S[N];
int tag[N];
int ans;
void dfs1(int k1,int k2){
	bool flg=0;
	each(x,e[k1])if(x!=k2){
		dfs1(x,k1);
		if(SZ(S[k1])<SZ(S[x]))swap(S[k1],S[x]),swap(tag[k1],tag[x]);
		each(y,S[x]){
			flg|=S[k1].count(y^tag[x]^a[k1]^tag[k1]);
		}
		each(y,S[x]){
			S[k1].insert(y^tag[x]^tag[k1]);
		}
		S[x].clear();
	}
	flg|=S[k1].count(a[k1]^tag[k1]);
	if(flg){
		S[k1].clear();
		++ans;
	}else{
		S[k1].insert(0^tag[k1]);
		tag[k1]^=a[k1];
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	rep(i,1,n)rd(a[i]);
	rep(i,2,n){
		int u,v;
		rd(u),rd(v);
		e[u].pb(v),e[v].pb(u);
	}
	dfs1(1,0);
	printf("%d\n",ans);
	return 0;
}