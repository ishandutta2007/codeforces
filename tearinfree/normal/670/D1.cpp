#include <bits/stdc++.h>
using namespace std;
typedef long long lli;

int n;
lli k,a[100000],b[1000000];

bool Check(lli cnt) {
	lli sum=0;
	for(int i=0;i<n;i++) {
		sum+=min(0ll,b[i]-a[i]*cnt);
		if(sum*-1>k) return false;
	}
	return true;
}
int main() {
	scanf("%d%lld",&n,&k);
	for(int i=0;i<n;i++) scanf("%lld",a+i);
	for(int i=0;i<n;i++) scanf("%lld",b+i);

	lli lo=0,up=2e9+1;
	for(int i=0;i<n;i++) up=min(up,(b[i]+k)/a[i]);
	up++;
	
	while(up-lo>1) {
		lli md=(lo+up)>>1;
		if(Check(md)) lo=md;
		else up=md;
	}
	printf("%lld\n",lo);

	return 0;
}