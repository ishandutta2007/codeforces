#include<bits/stdc++.h>

using namespace std;
void solve(){
	long long n,k;
	scanf("%lld%lld",&n,&k);
	long long v=1,s=0;
	for (;v<n&&v<=k;v*=2,++s);
	if (v<n) s+=(n-v+k-1)/k;
	printf("%lld\n",s);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}