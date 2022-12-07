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
const int N=500005;
int n,m,fa[N],dep[N],vis[N],mxd;
vector<int> e[N],v[N];
void dfs(int x){
	mxd=max(mxd,dep[x]);
	v[dep[x]].PB(x);
	vis[x]=1;
	for (auto i:e[x])
		if (i!=fa[x]&&!vis[i]){
			fa[i]=x;
			dep[i]=dep[x]+1;
			dfs(i);
		}
}
void solve(){
	mxd=0; dep[1]=1;
	scanf("%d%d",&n,&m);
	For(i,1,n) vis[i]=0,e[i].resize(0),v[i].resize(0);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1);
	if (mxd>=(n+1)/2){
		int x=v[mxd][0];
		printf("PATH\n%d\n",dep[x]);
		for (;x;x=fa[x]) printf("%d ",x);
		puts("");
	}
	else{
		int res=n;
		For(i,1,mxd) res-=(v[i].size()&1);
		printf("PAIRING\n%d\n",res/2);
		For(i,1,mxd)
			for (int j=0;j+1<v[i].size();j+=2)
				printf("%d %d\n",v[i][j],v[i][j+1]);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}