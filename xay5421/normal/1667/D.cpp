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
int T,n,dp[N][2],fa[N];
bool err;
vector<int>e[N];
bool check(int odd,int even,int any){
	int deg=odd+even+any;
	while(deg){
		if(deg&1){
			if(odd)--odd;
			else if(any)--any;
			else return 0;
		}else{
			if(even)--even;
			else if(any)--any;
			else return 0;
		}
		--deg;
	}
	return 1;
}

void dfs1(int k1,int k2){
	fa[k1]=k2;
	dp[k1][0]=dp[k1][1]=0;
	int odd=0,even=0,any=0;
	each(x,e[k1])if(x!=k2){
		dfs1(x,k1);
		if(err)return;
		if(dp[x][0]&&dp[x][1]){
			++any;
		}else if(dp[x][0]){
			++even;
		}else{
			++odd;
		}
	}
	tuple<int,int,int>old=make_tuple(odd,even,any);
	if(k1!=1){
		rep(o,0,1){
			if(o){
				++odd;
			}else{
				++even;
			}
			
			if(check(odd,even,any)){
				dp[k1][o]=1;
			}
			
			tie(odd,even,any)=old;
		}
		if(!dp[k1][0]&&!dp[k1][1]){
			err=1;
		}
	}else{
		if(err||!check(odd,even,any)){
			err=1;
		}else{
			
		}
	}
}
int nex[N];
int back(vector<int>&a){
	int ret=a.back();
	a.pop_back();
	return ret;
}
void dfs2(int k1,int k2,int k3){
	vector<int>odd,even,any;
	each(x,e[k1])if(x!=k2){
		if(dp[x][0]&&dp[x][1]){
			any.pb(x);
		}else if(dp[x][0]){
			even.pb(x);
		}else{
			odd.pb(x);
		}
	}
	if(k1!=1){
		if(k3)odd.pb(k2);
		else even.pb(k2);
	}
	int deg=SZ(e[k1]);
	while(deg){
		int u;
		if(deg&1){
			if(!odd.empty()){
				u=back(odd);
			}else{
				u=back(any);
			}
			if(u!=k2)dfs2(u,k1,1);
		}else{
			if(!even.empty()){
				u=back(even);
			}else{
				u=back(any);
			}
			if(u!=k2)dfs2(u,k1,0);
		}
		if(u==k2)printf("%d %d\n",k1,k2);
		--deg;
	}
}
int main(){
	rd(T);
	while(T--){
		err=0;
		rd(n);
		rep(i,1,n)e[i].clear();
		rep(i,2,n){
			int u,v;
			rd(u),rd(v);
			e[u].pb(v),e[v].pb(u);
		}
		dfs1(1,0);
		if(err){
			puts("NO");
		}else{
			puts("YES");
			dfs2(1,0,0);
		}
	}
	return 0;
}