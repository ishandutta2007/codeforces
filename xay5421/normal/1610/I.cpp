#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
const int N=300005;
int n,sg[N],f[N],fa[N];
bool vis[N];
vector<int>e[N];
void dfs1(int k1,int k2){
	fa[k1]=k2;
	sg[k1]=0;
	for(auto x:e[k1])if(x!=k2)dfs1(x,k1),sg[k1]^=sg[x];
	++sg[k1];
	for(auto x:e[k1])if(x!=k2){
		f[k1]^=sg[x];
	}
}
int all,tot;
void sol(int x){
	while(!vis[x]){
		vis[x]=1;
		all^=f[x];
		if(x!=1)all^=sg[x];
		x=fa[x],++tot;
	}
}
int main(){
	scanf("%d",&n);
	rep(i,2,n){
		int k1,k2;
		scanf("%d%d",&k1,&k2);
		e[k1].pb(k2),e[k2].pb(k1);
	}
	dfs1(1,0);
	rep(i,1,n){
		sol(i);
		putchar((all^(tot&1))?'1':'2');
	}
	puts("");
	return 0;
}