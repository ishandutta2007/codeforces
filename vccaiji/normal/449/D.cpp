#include<bits/stdc++.h>
using namespace std;
int num[1<<20]={};//
long long p[1100000];
const long long mod=1000000007;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		num[a]++;
	}
	for(int i=0;i<20;i++){
		for(int j=0;j<(1<<20);j++){
			if(j&(1<<i)) num[j^(1<<i)]+=num[j];
		}
	}
	p[0]=1;
	for(int i=1;i<=1000000;i++) p[i]=(p[i-1]<<1)%mod;
	long long ans=0;
	for(int j=0;j<(1<<20);j++){
		int par=p[num[j]];
		for(int k=0;k<20;k++) if((j>>k)&1) par=-par;
		ans+=par;
	}
	printf("%lld",(ans%mod+mod)%mod);
	return 0;
}