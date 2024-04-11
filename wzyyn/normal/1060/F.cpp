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
const int N=55;
vector<int> e[N];
double f[N][N],g[N];
double fac[N],inv[N];
int n,sz[N]; 
void init(){
	fac[0]=inv[0]=1;
	For(i,1,N-1) fac[i]=fac[i-1]*i;
	For(i,1,N-1) inv[i]=inv[i-1]/i;
}
double C(int x,int y){
	return fac[x]*inv[y]*inv[x-y];
}
void dfs(int x,int fa){
	For(i,0,n) f[x][i]=0;
	f[x][1]=1; sz[x]=1;
	for (auto y:e[x]) if (y!=fa){
		dfs(y,x);
		For(i,0,n) g[i]=0;
		For(i,1,sz[x]) For(j,1,sz[y]) For(l,0,sz[y])
			g[i+l]+=f[x][i]*f[y][min(j,l+1)]*C(i+l-1,i-1)*C(sz[x]-i+sz[y]-l,sz[x]-i)*(j<=l?0.5:1);
		sz[x]+=sz[y];
		For(i,0,sz[x]) f[x][i]=g[i];
	}
}
int main(){
	init();
	scanf("%d",&n);
	For(i,1,n-1){ 
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	For(i,1,n){
		dfs(i,0);
		printf("%.10lf\n",f[i][n]*inv[n-1]);
	}
	puts("");
}