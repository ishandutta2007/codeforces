#include <bits/stdc++.h>
using namespace std;

int n;
int a[200013];
int high[200013];
int can[200013];
vector<int> divisors;
vector<int> need[200013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	int allsame = 1;
	for (int i=1;i<n;i++) if (a[i]!=a[0]) allsame = 0;
	if (allsame) return printf("%lld\n",1LL*n*(n-1)), 0;

	for (int i=1;i<n;i++) if (n%i==0) divisors.push_back(i);
	for (int i=1;i<n;i++) need[__gcd(i,n)].push_back(i);

	long long ans = 0;
	for (int i: divisors) {
		for (int j=0;j<i;j++) high[j] = 0;
		for (int j=0;j<n;j++) high[j%i] = max(high[j%i],a[j]);
		for (int j=0;j<n;j++) can[j] = (a[j]==high[j%i]);
		for (int j=0;j<n;j++) if (can[j]) can[j] = 1+can[(j-1+n)%n];
		for (int j=0;j<n;j++) if (can[j]) can[j] = 1+can[(j-1+n)%n];
		for (int j=0;j<=n;j++) high[j] = 0;
		for (int j=0;j<=n;j++) high[min(can[j],n)]+=1;
		for (int j=n-1;j>0;j--) high[j]+=high[j+1];
		for (int l: need[i]) ans+=high[l];
	}
	printf("%lld\n",ans);

	return 0;
}