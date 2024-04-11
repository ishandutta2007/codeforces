#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int inv(int x) {
	int p = MOD-2;
	int ans = 1;
	int cur = x;
	while (p) {
		if (p&1) ans = ((long long) ans*cur)%MOD;
		p>>=1;
		cur = ((long long) cur*cur)%MOD;
	}
	return ans;
}

int n;
int fact[1000013];

int main() {
	fact[0] = 1;
	for (int i=1;i<1000013;i++) fact[i] = ((long long) fact[i-1]*i)%MOD;
	scanf("%d",&n);
	n+=1;
	int ans = 0;
	for (int k=1;k<=n;k++) {
		int cur = fact[n];
		cur = ((long long) cur*inv(fact[k]))%MOD;
		cur = ((long long) cur*inv(fact[n-k]))%MOD;
		cur = ((long long) cur*cur)%MOD;
		ans = (ans+cur)%MOD;
	}
	printf("%d\n",ans);

	return 0;
}