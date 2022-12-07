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
int n,m,nd,a[N];
int id[N*2],fa[N*2][20];
int dep[N*2],ans[N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,m) id[i]=i,fa[i][0]=i;
	nd=m;
	For(i,1,m-1){
		int x,y;
		scanf("%d%d",&x,&y);
		fa[id[x]][0]=fa[id[y]][0]=++nd;
		id[x]=nd;
	}
	Rep(i,nd,1) dep[i]=dep[fa[i][0]]+1;
	For(i,1,18) For(j,1,nd)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	ans[0]=n-1;
	For(i,1,n-1){
		int x=a[i],y=a[i+1];
		if (dep[x]<dep[y]) swap(x,y);
		int tmp=dep[x]-dep[y];
		Rep(j,18,0)
			if (tmp&(1<<j))
				x=fa[x][j];
		Rep(j,18,0)
			if (fa[x][j]!=fa[y][j])
				x=fa[x][j],y=fa[y][j];
		if (x!=y) x=fa[x][0];
		//cout<<x<<' '<<tmp<<endl;
		if (x<=m) --ans[0];
		else --ans[x-m];
	}
	For(i,1,m-1) ans[i]+=ans[i-1];
	For(i,0,m-1) printf("%d\n",ans[i]);
}