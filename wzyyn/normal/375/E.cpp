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
const int N=505;
int n,X,tot,S,sz[N];
int head[N],a[N];
ll d[N][N];
short tmp[N];
short ff[N][N];
short f[N][N][N];
struct edge{
	int to,next;
}e[N*2];

void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x,int fa){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa) dfs(e[i].to,x);
	For(i,1,n) if (d[x][i]<=X){
		sz[x]=1; f[x][i][1]=1-a[i];
		for (int j=head[x];j;j=e[j].next)
			if (e[j].to!=fa){
				int y=e[j].to;
				For(k,0,sz[x]+sz[y]) tmp[k]=10000;
				For(k,0,sz[x]) For(l,0,sz[y]){
					tmp[k+l]=min(tmp[k+l],(short)(f[x][i][k]+ff[y][l]));
					tmp[k+l]=min(tmp[k+l],(short)(f[x][i][k]+f[y][i][l+1]-(1-a[i])));
				}
				sz[x]+=sz[y];
				For(k,0,sz[x]) f[x][i][k]=tmp[k];
			}
		For(j,0,sz[x]){
			ff[x][j]=min(ff[x][j],f[x][i][j]);
			//cout<<x<<' '<<i<<' '<<j<<' '<<f[x][i][j]<<endl;
		}
	}
}
int main(){
	scanf("%d%d",&n,&X);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) S+=a[i];
	For(i,1,n) For(j,1,n)
		d[i][j]=(i==j?0:1ll<<60);
	For(i,1,n-1){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y); add(y,x);
		d[x][y]=d[y][x]=v;
	}
	For(k,1,n) For(i,1,n) For(j,1,n)
		d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	//cout<<d[1][3]<<endl; 
	memset(f,30,sizeof(f));
	memset(ff,30,sizeof(ff));
	dfs(1,0);
	short ans=23333;
	For(i,1,S) ans=min(ans,ff[1][i]);
	printf("%d\n",ans>1000?-1:ans);
}