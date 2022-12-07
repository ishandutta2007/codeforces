#include<bits/stdc++.h>
using namespace std;

const int N=405;
const int mo=1000000007;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int fac[N];
int inv[N];
int C[N][N];
int f[N][N];
int n,k;
void init(){
	fac[0]=1;
	for (int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mo;
	for (int i=1;i<N;i++)
		inv[i]=power(i,mo-2);
	for (int i=0;i<N;i++) C[i][0]=1;
	for (int i=1;i<N;i++)
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mo;
}
int main(){
	init();
	scanf("%d%d",&n,&k);
	f[0][0]=1;
	for (int i=0;i<=k;i++)
		for (int j=0;j<=2*i;j++)
			for (int p=1;p<=k-i;p++)
				f[i+p][j+p+1]=(f[i+p][j+p+1]+1ll*f[i][j]*fac[p]%mo*C[j+p][p])%mo;
	for (int T=1;T<=k;T++){
		int ans=0;
		for (int i=0;i<=2*T;i++){
			int s=0;
			for (int j=T;j>=0;j-=2)
				s=(s+f[j][i])%mo;
			for (int j=1;j<=i;j++)
				s=1ll*s*(n+1-j)%mo*inv[j]%mo;
			ans=(ans+s)%mo;
		}
		cout<<ans<<' ';
	}	
}