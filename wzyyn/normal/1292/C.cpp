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
const int N=3005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void getfir(int *d,int *sz,int x,int fa){
	if (!d[fa]) d[x]=x;
	else d[x]=d[fa];
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			getfir(d,sz,e[i].to,x);
			sz[x]+=sz[e[i].to];
		}
}
int v[N][N];
int sz[N][N];
int vis[N][N];
int x[N],y[N],ans;
ll f[N][N];
ll F(int x,int y){
	if (vis[x][y]) return f[x][y];
	vis[x][y]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=v[x][y])
			f[x][y]=max(f[x][y],F(e[i].to,y));
	for (int i=head[y];i;i=e[i].next)
		if (e[i].to!=v[y][x])
			f[x][y]=max(f[x][y],F(x,e[i].to));
	f[x][y]+=sz[x][y]*sz[y][x];
	return f[x][y];
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		scanf("%d%d",&x[i],&y[i]);
		add(x[i],y[i]); add(y[i],x[i]);
	}
	For(i,1,n)
		for (int j=head[i];j;j=e[j].next)
			getfir(v[i],sz[i],e[j].to,i);
	ll ans=0;
	For(i,1,n-1) ans=max(ans,F(x[i],y[i]));
	cout<<ans<<endl;
}
/*

*/