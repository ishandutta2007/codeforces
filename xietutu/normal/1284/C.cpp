#include <bits/stdc++.h>
using namespace std;

int n, m, Ans;
int jc[300005];

int main() {
	scanf("%d%d", &n, &m); 
	jc[0] = 1;
	for (int i = 1; i <= n; ++ i) jc[i] = 1ll * jc[i - 1] * i % m;
	for (int l = 1; l <= n; ++ l) {
		Ans = (Ans + 1ll * (n - l +  1) * (n - l + 1) % m * jc[l] % m * jc[n - l]) % m;
	}
	printf("%d\n", Ans);
	return 0; 
}