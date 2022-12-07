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
const int N=205;
int n,m,ans[2][N];
int a[N][N],b[N][N];
void flip(int x,int y,int z){
	ans[x][y]=z;
	if (x==0) For(j,1,m) a[y][j]^=z;
	else For(j,1,n) a[j][y]^=z;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,m) scanf("%d",&b[i][j]);
	For(v1,0,1)	For(j,0,n+m-1){
		memcpy(a,b,sizeof(a));
		flip(0,1,v1);
		For(k,1,n+m-1)
			if (k<=m) flip(1,k,a[1][k]^(k>j));
			else flip(0,k-m+1,a[k-m+1][1]^(k>j));
		bool flag=1;
		For(k,1,n) For(l,1,m-1) if (a[k][l]>a[k][l+1]) flag=0;
		For(k,1,n-1) if (a[k][m]>a[k+1][1]) flag=0;
		if (flag){
			puts("YES");
			For(i,1,n) printf("%d",ans[0][i]); puts("");
			For(i,1,m) printf("%d",ans[1][i]); puts("");
			exit(0);
		}
	}
	puts("NO");
}