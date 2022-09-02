// author: xay5421
// created: Fri Jun 18 22:33:08 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
int T,n,m,x[N],dep[N];
bool odd;
vector<int>e[N];
void dfs1(int k1,int _dep){
	if(dep[k1]==-1){
		dep[k1]=_dep;
	}else{
		if((dep[k1]&1)!=(_dep&1))odd=1;
		return;
	}
	for(int x:e[k1]){
		dfs1(x,_dep+1);
	}
}
int main(){
	rd(T);
	while(T--){
		rd(n),rd(m);
		rep(i,1,n){
			rd(x[i]);
		}
		rep(i,1,n){
			int _;
			rd(_);
			x[i]-=_;
		}
		rep(i,1,n)e[i].clear();
		rep(i,1,m){
			int k1,k2;
			rd(k1),rd(k2);
			e[k1].push_back(k2);
			e[k2].push_back(k1);
		}
		fill(dep+1,dep+1+n,-1);
		odd=0;
		dfs1(1,0);
		LL s[2]={0,0};
		rep(i,1,n)assert(dep[i]!=-1),s[dep[i]&1]+=x[i];
		if(odd){
			if((s[0]+s[1])&1)puts("NO");else puts("YES");
		}else{
			if(s[0]==s[1])puts("YES");else puts("NO");
		}
	}
	return 0;
}