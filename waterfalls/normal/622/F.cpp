#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;
int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }
int mult(int a, int b) { return ((ll) a*b)%MOD; }
int binpow(int a, int p=MOD-2) {
	int ans = 1;
	while (p) {
		if (p&1) ans = mult(ans,a);
		p>>=1;
		a = mult(a,a);
	}
	return ans;
}

int n,k;
int up[1000013], down[1000013];

int main() {
	scanf("%d%d",&n,&k);
	int prod = 1;
	for (int i=0;i<=k+1;i++) prod = mult(prod,n-i);
	up[0] = down[0] = 1;
	for (int i=1;i<=k+1;i++) up[i] = mult(up[i-1],i);
	for (int i=1;i<=k+1;i++) down[i] = mult(down[i-1],MOD-i);
	int ans = 0;
	int cur = 0;
	for (int i=0;i<=k+1;i++) {
		if (i) cur = add(cur,binpow(i,k));
		if (prod==0 && n==i) ans = cur;
		int top = mult(prod,binpow(n-i));
		int bot = binpow(mult(up[i],down[k+1-i]));
		ans = add(ans,mult(mult(top,bot),cur));
	}
	printf("%d\n",ans);

	return 0;
}