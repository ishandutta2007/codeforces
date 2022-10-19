#include<bits/stdc++.h>
using namespace std;
int n,mod,f[8001000],g[8001000];
int main(){
	scanf("%d%d",&n,&mod);
	f[n]=1;
	for(int i=n-1;i>=1;i--){
		g[i]=(g[i+1]+f[i+1])%mod;
		(f[i]+=g[i])%=mod;
		g[i-1]=g[i];
		for(int j=1;i*j<=n;j++)(f[i]+=(g[i*j-1]+mod-g[(i+1)*j-1])%mod)%=mod;
	}
	printf("%d\n",f[1]);
	return 0;
}