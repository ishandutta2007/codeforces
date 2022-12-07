#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;
const int mo=1000000007;
const int N=55;
int n,m,inv[N],tr[N];
int g[N][N],f[N][N];
int main(){
	scanf("%d%d",&n,&m);
	f[0][1]=inv[0]=inv[1]=tr[0]=1;
	For(i,2,N-1) inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	For(i,1,n){
		For(j,0,i-1) For(v1,1,j+1) For(v2,1,i-j)
			g[i][min(v1,v2)]=(g[i][min(v1,v2)]+1ll*f[j][v1]*f[i-j-1][v2])%mo;
		For(j,1,n+1){
			For(k,1,n/max(i,j)) tr[k]=1ll*tr[k-1]*inv[k]%mo*(g[i][j]+k-1)%mo;
			Rep(v1,n,i) Rep(v2,n+1,j) For(k,1,min(v1/i,v2/j))
				f[v1][v2]=(f[v1][v2]+1ll*f[v1-i*k][v2-j*k]*tr[k])%mo;
		}
	}
	printf("%d\n",f[n][m]);
}