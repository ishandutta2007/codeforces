#include<bits/stdc++.h>

int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	-- k;
	int ans1 = k / (2 * m), ans2 = k % (2 * m) / 2;
	printf("%d %d ", ans1 + 1, ans2 + 1);
	printf(k & 1 ? "R" : "L");
	return 0;
}