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
const int N=2005;
int f[N][N],g[N][N];
int n,m,Q;
int main(){
	scanf("%d%d%d",&n,&m,&Q);
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int mn=1<<30,px=0,py=0;
		Rep(i,x,1) if (x-i<=mn){
			int d=x-i+g[i][y];
			if (d<=mn){
				mn=d; px=i;
				if (y>g[i][y]&&!f[i][y-g[i][y]])
					py=y-g[i][y];
				else py=y+g[i][y];
			}
		}
		For(i,x,n) if (i-x<=mn){
			int d=i-x+g[i][y];
			if (d<mn){
				mn=d; px=i;
				if (y>g[i][y]&&!f[i][y-g[i][y]])
					py=y-g[i][y];
				else py=y+g[i][y];
			}
		}
		f[px][py]=1;
		printf("%d %d\n",px,py,mn);
		For(j,1,m) g[px][j]=(f[px][j]?1<<30:0);
		For(j,2,m) g[px][j]=min(g[px][j],g[px][j-1]+1);
		Rep(j,m-1,1) g[px][j]=min(g[px][j],g[px][j+1]+1);
	}
}