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
const int N=100005;
vector<int> e[N];
int vis[N],ban[N];
int n,m,id[N],tried[N];
bool dfs(int x){
	if (ban[x]) return 0;
	vis[x]=1;
	for (auto i:e[x])
		if (!vis[i]){
			if (dfs(i)) return 1;
		}
		else if (vis[i]==1){
			For(j,1,n) if (vis[j]!=1) tried[j]=1;
			return 1;
		}
	vis[x]=2;
	return 0;
}
bool check(){
	memset(vis,0,sizeof(vis));
	For(i,1,n) if (!vis[i])
		if (dfs(i)) return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); 
	} 
	For(i,1,n) id[i]=i;
	random_shuffle(id+1,id+n+1);
	For(i,1,n){
		if (1.0*clock()/CLOCKS_PER_SEC>0.95) break;
		if (tried[id[i]]) continue;
		ban[id[i]]=1;
		if (check()){
			printf("%d ",id[i]);
			return 0;
		}
		ban[id[i]]=0;
	}
	puts("-1");
}