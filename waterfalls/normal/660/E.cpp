#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }
int sub(int a, int b) { return a-b+(a-b<0)*MOD; }
int mult(int a, int b) { return (1LL*a*b)%MOD; }

int n,m;

int main() {
	scanf("%d%d",&n,&m);
	int pow = 1;
	int ans = 1;
	for (int i=1;i<=n;i++) {
		ans = mult(ans, 2*m-1);
		ans = sub(ans, mult(m-1, pow));
		pow = mult(pow, m);
		ans = add(ans, pow);
	}
	printf("%d\n", ans);

	return 0;
}