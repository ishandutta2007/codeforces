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
#define all(v) v.begin(),v.end()
using namespace std;
const int N=200005;
int n,m,s,deg[N];
vector<int> e[N];
int q[N],vis[N],f[N];
void topo_sort(){
	int h=0,t=0;
	For(i,1,n) if (!deg[i]) q[++t]=i;
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x]) if (!--deg[i]) q[++t]=i;
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n){
		deg[i]=vis[i]=f[i]=0;
		e[i].resize(0);
	}
	s=0;
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); ++deg[y];
	}
	topo_sort();
	For(i,1,n){
		int x=q[i];
		//cout<<f[x]<<en
		if (vis[x]==1){
			++s; continue;
		}
		if (f[x]==2)
			for (auto j:e[x]) vis[j]=1;
		else for (auto j:e[x]) f[j]=2;
	}
	cout<<s<<endl;
	For(i,1,n) if (vis[i]) cout<<i<<' ';
	cout<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}