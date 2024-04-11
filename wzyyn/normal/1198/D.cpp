#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=55;
int n,a[N][N],b[N][N];
int f[N][N][N][N];
char s[N][N];
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%s",s[i]+1);
		For(j,1,n) a[i][j]=b[i][j]=(s[i][j]=='#');
	}
	For(i,1,n) For(j,1,n)
		a[i][j]+=a[i][j-1],b[i][j]+=b[i-1][j];
	Rep(i,n,1) For(j,i,n) Rep(k,n,1) For(l,k,n){	
		f[i][j][k][l]=max(j-i+1,l-k+1);
		For(p,i,j) if (a[p][k-1]==a[p][l])
			f[i][j][k][l]=min(f[i][j][k][l],f[i][p-1][k][l]+f[p+1][j][k][l]);
		For(p,k,l) if (b[i-1][p]==b[j][p])
			f[i][j][k][l]=min(f[i][j][k][l],f[i][j][k][p-1]+f[i][j][p+1][l]);
	}
	printf("%d",f[1][n][1][n]);
}