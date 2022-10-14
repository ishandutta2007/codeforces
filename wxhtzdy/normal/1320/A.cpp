#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%i",&n);
	long long a[n];
	map<int,long long> mp;
	for(int i=0;i<n;i++)scanf("%lld",&a[i]),mp[a[i]-i]+=a[i];
	long long ans=0;
	for(int i=0;i<n;i++)ans=max(ans,mp[a[i]-i]);
	printf("%lld",ans);
	return 0;
}