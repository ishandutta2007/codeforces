#include <bits/stdc++.h>
using namespace std;

int n;
int a[26];
set<int> has;

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n,greater<int>());
	long long ans = 0;
	for (int i=0;i<n;i++) {
		while (a[i] && has.count(a[i])) a[i]-=1;
		has.insert(a[i]);
		ans+=a[i];
	}
	printf("%lld\n",ans);

	return 0;
}