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
int n,d,mo,ans,tr[N];
int C[N][N],f[N][N];
int main(){
	scanf("%d%d%d",&n,&d,&mo);
	For(i,0,n) C[i][0]=1%mo;
	For(i,1,n) For(j,1,i)
		C[i][j]=(1ll*C[i-1][j]+C[i-1][j-1])%mo;
	f[1][0]=1;
	For(i,1,n){
		int S=0; tr[0]=1;
		For(j,0,d-1) S=(1ll*S+f[i][j])%mo;
		For(j,1,min(n/i,d)) tr[j]=1ll*tr[j-1]*C[i*j-1][i-1]%mo*S%mo;
		Rep(j,n,0) For(k1,1,min(n/i,d)) For(k2,0,d-k1)
			f[j][k1+k2]=(f[j][k1+k2]+1ll*f[j-k1*i][k2]*tr[k1]%mo*C[j-1][k1*i])%mo;
	}
	For(i,0,n-1) For(j,0,d) For(k,0,d-j)
		if (k!=1) ans=(ans+1ll*f[i+1][j]*f[n-i][k])%mo;
	printf("%d\n",2ll*n*(n-1)*ans%mo);
}