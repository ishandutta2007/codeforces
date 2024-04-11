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
const int N=255;
int n,m,a[N][N];
int f[N][N],vn[N*N],vm[N*N];
pii q[N*N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,m) scanf("%d",&a[i][j]);
	For(i,1,n){
		int v=0;
		For(j,1,m) v=max(v,a[i][j]);
		vn[v]=1;
	}
	For(i,1,m){
		int v=0;
		For(j,1,n) v=max(v,a[j][i]);
		vm[v]=1;
	}
	int h=1,t=0,x=0,y=0;
	Rep(i,n*m,1){
		x+=vn[i]; y+=vm[i];
		if (vn[i]||vm[i]) f[x][y]=i;
		else{
			assert(h<=t);
			pii tmp=q[h++];
			f[tmp.fi][tmp.se]=i;
		}
		if (vm[i])
			Rep(i,x-1,1)
				q[++t]=pii(i,y);
		if (vn[i])
			Rep(i,y-1,1)
				q[++t]=pii(x,i);
	}
	For(i,1,n)
		For(j,1,m)
			printf("%d%c",f[i][j],j==m?'\n':' ');
}