#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define uint unsigned
using namespace std;
const int mo=998244353;
const int N=505;
int n,m,rk[N],p[N];
int mn[N][N],f[N][N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&rk[i]);
	For(i,1,n+1) f[i][i-1]=1;
	For(i,1,n) mn[i][i]=i;
	For(i,1,n) For(j,i+1,n)
		mn[i][j]=(rk[j]<rk[mn[i][j-1]]?j:mn[i][j-1]);
	Rep(i,n,1) For(j,i,n){
		int pos=mn[i][j],v1=0,v2=0;
		For(k,i-1,pos-1) v1=(v1+1ll*f[i][k]*f[k+1][pos-1])%mo;
		For(k,pos+1,j+1) v2=(v2+1ll*f[k][j]*f[pos+1][k-1])%mo;
		f[i][j]=1ll*v1*v2%mo;
	}
	printf("%d\n",f[1][n]);
}