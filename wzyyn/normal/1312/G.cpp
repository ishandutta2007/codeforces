#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=1000005;
char s[10];
int n,P,dfn[N],T;
int vis[N],f[N],q[N];
vector<pii> e[N];
void dfs(int x){
	if (vis[x]) ++T;
	dfn[x]=T;
	sort(e[x].begin(),e[x].end());
	for (auto i:e[x]) dfs(i.se);
}
void DP(int x,int v){
	if (vis[x]) f[x]=min(f[x],v+dfn[x]);
	v=min(v,f[x]-dfn[x]+(vis[x]==1&&x));
	for (auto i:e[x]) f[i.se]=f[x]+1,DP(i.se,v);
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x;
		scanf("%d%s",&x,s+1);
		e[x].PB(pii(s[1]-'a',i));
	}
	scanf("%d",&P);
	For(i,1,P){
		scanf("%d",&q[i]);
		vis[q[i]]=1;
	}
	vis[0]=1;
	dfs(0);
	memset(f,30,sizeof(f));
	f[0]=0;
	DP(0,1<<30);
	For(i,1,P)
		printf("%d ",f[q[i]]);
}
/*
f[i]:i
1:
2:list 
*/