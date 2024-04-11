#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,q;
int has[3000013];
ll ans[3000013];

int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		int a;
		scanf("%d",&a);
		has[a]+=1;
	}
	for (int i=1;i<3000013;i++) {
		for (int j=1;i*j<3000013;j++) {
			ans[i*j]+=(ll) has[i]*(has[j]-(i==j));
		}
	}
	for (int i=1;i<3000013;i++) ans[i]+=ans[i-1];
	scanf("%d",&q);
	while (q--) {
		int a;
		scanf("%d",&a);
		printf("%lld\n",(ll) n*(n-1)-ans[a-1]);
	}

	return 0;
}