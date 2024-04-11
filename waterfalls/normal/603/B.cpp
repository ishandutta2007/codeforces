#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9+7;
int add(int a, int b, int mo=MOD) { return (a+b)%mo; }
int sub(int a, int b, int mo=MOD) { return (a-b+mo)%mo; }
int mult(int a, int b, int mo=MOD) { return ((ll) a*b)%mo; }
int binpow(int x, int p, int mo=MOD) {
	int ans = 1;
	while (p) {
		if (p&1) ans = mult(ans,x,mo);
		x = mult(x,x,mo);
		p>>=1;
	}
	return ans;
}

int order(int k, int p) {
	int ans = p-1;
	for (int i=2;i*i<=p;i++) if ((p-1)%i==0) {
		if (binpow(k,i,p)==1) ans = min(ans,i);
		if (binpow(k,(p-1)/i,p)==1) ans = min(ans,(p-1)/i);
	}
	return ans;
}

int k,p;

int main() {
	scanf("%d%d",&p,&k);
	if (k==0) printf("%d\n",binpow(p,p-1));
	else if (k==1) printf("%d\n",binpow(p,p));
	else printf("%d\n",binpow(p,(p-1)/order(k,p)));

	return 0;
}