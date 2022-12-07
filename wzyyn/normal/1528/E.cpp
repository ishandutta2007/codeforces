#include<bits/stdc++.h>
using namespace std;

const int N=1000005;
const int mo=998244353;
int n,ans;
int f[N],sf[N];
int main(){
	int n;
	scanf("%d",&n);
	if (n==1){
		puts("5");
		return 0;
	}
	f[0]=1; sf[0]=1;
	for (int i=1;i<=n;i++){
		f[i]=(f[i-1]+1ll*f[i-1]*(f[i-1]+1)/2)%mo;
		if (i!=1) f[i]=(f[i]+1ll*f[i-1]*sf[i-2])%mo;
		sf[i]=(sf[i-1]+f[i])%mo;
	}
	ans=f[n];
	ans=(ans+1ll*sf[n-2]*(sf[n-2]+1)/2%mo*f[n-1])%mo;
	ans=(ans+1ll*f[n-1]*(f[n-1]+1)/2%mo*(sf[n-2]))%mo;
	ans=(ans+1ll*f[n-1]*(f[n-1]+1)%mo*(f[n-1]+2)%mo*(mo+1)/6)%mo;
	ans=(2ll*ans+mo-1)%mo;
	
	for (int i=1;i<n-1;i++)
		ans=(ans+1ll*(f[i]+mo-1)*(f[n-i-1]+mo-f[n-i-2]))%mo;
	cout<<ans<<endl;
}
/*
f=f
*/