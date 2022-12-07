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

const int N=200005;
vector<int> e[N];
int n,sz[N],fa[N],vis[N];
int inq[N];
void dfs(int x,int fa){
	//cout<<x<<' '<<fa<<endl;
	inq[x]=1; ::fa[x]=fa;
	for (auto i:e[x])
		if (i!=fa){
			if (!inq[i])
				dfs(i,x);
			else{
				vis[i]=1;
				for (int y=x;y!=i;y=::fa[y]) vis[y]=1;
			}
		}
	inq[x]=0;
}
void dfs2(int x,int fa){
	sz[x]=1;
	for (auto i:e[x])
		if (i!=fa){
			dfs2(i,x);
			sz[x]+=sz[i];
		}
}
void solve(){
	scanf("%d",&n);
	For(i,1,n) e[i].resize(0);
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y);
		e[y].PB(x);
	}
	For(i,1,n) vis[i]=0;
	dfs(1,0);
	ll ans=1ll*n*(n-1);
	For(i,1,n) if (vis[i]){
		int s=1;
		for (auto j:e[i]) if (!vis[j])
			dfs2(j,i),s+=sz[j];
		ans-=1ll*s*(s-1)/2;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}