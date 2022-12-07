#include<bits/stdc++.h>

using namespace std;

const int N=10000005;
const int L=16*9*5*7*11*13;
const int mo=998244353;
int n,va,ans;
int X,Y,k,M;
int f[L],g[L];
int main(){
	scanf("%d%d%d%d%d%d",&n,&va,&X,&Y,&k,&M);
	for (int i=1;i<=n;i++){
		++f[va%L];
		ans=(ans+va/L*L)%mo;
		va=(1ll*va*X+Y)%M;
	}
	ans=1ll*ans*k%mo;
	for (int i=1;i<k;i++)
		ans=1ll*ans*n%mo;
	int va=0;
	for (int i=1;i<=min(k,16);i++){
		va=1ll*va*n%mo;
		memset(g,0,sizeof(g));
		for (int j=0;j<L;j++){
			int nj=j-j%i;
			g[j]=(g[j]+1ll*f[j]*(n-1))%mo;
			va=(va+1ll*f[j]*j)%mo;
			g[nj]=(g[nj]+f[j])%mo;
		}
		memcpy(f,g,sizeof(f));
	}
	if (k==17){
		va=1ll*va*n%mo;
		for (int j=0;j<L;j++)
			va=(va+1ll*f[j]*j)%mo;
	}
	printf("%d\n",(ans+va)%mo);
}