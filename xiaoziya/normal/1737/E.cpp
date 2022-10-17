#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005,mod=1000000007,inv2=(mod+1)/2;
int n,T;
int f[maxn],mul[maxn];
int main(){
	mul[0]=1;
	for(int i=1;i<=1000000;i++)
		mul[i]=1ll*mul[i-1]*inv2%mod;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==1){
			puts("1");
			continue;
		}
		int sum=0;
		for(int i=n,j=n;i>=2;i--){
			f[i]=1ll*(i==n? 1:inv2)*mul[(i-1)/2]%mod;
			while(j-(j-1)/2-1>=i)
				sum=(sum+f[j])%mod,j--;
			f[i]=1ll*f[i]*(1-sum+mod)%mod;
		}
		for(int i=1;i<=n;i++)
			printf("%d\n",f[i]);
	}
	return 0;
}