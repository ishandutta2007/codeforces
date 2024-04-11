#include <bits/stdc++.h>
using namespace std;

int n;
int loc[200013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int f;
		scanf("%d",&f);
		loc[f] = i;
	}
	long long ans = 0;
	for (int i=2;i<=n;i++) ans+=abs(loc[i]-loc[i-1]);
	printf("%lld\n",ans);

	return 0;
}