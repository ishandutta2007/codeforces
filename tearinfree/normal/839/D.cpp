#include <cstdio>
#include <algorithm>

typedef long long lli;
const lli mod=1e9+7;

int n,arr[200000];
lli cnt[1000001],ans[10000001];

lli power(lli a, lli p) {
	lli res=1;
	while(p) {
		if(p&1) res=res*a%mod;
		a=a*a%mod;
		p>>=1;
	}
	return res;
}
int main() {
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d",arr+i);
		for(int j=2;j*j<=arr[i];j++) {
			if(arr[i]%j==0) {
				cnt[j]++; 
				if(arr[i]/j!=j) cnt[arr[i]/j]++;
			}
		}
		if(arr[i]!=1) cnt[arr[i]]++;
	}
	
	lli sum=0;
	for(int i=1000000;i>1;i--) {
		if(cnt[i]==0) continue;
		ans[i]=cnt[i]*power(2,cnt[i]-1)%mod;
		for(int j=i+i;j<=1000000;j+=i) ans[i]-=ans[j];
		sum=(sum+i*ans[i]%mod)%mod;
	}
	while(sum<0) sum+=mod;
	printf("%lld\n",sum);
	
	return 0;
}