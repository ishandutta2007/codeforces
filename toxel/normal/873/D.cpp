#include<bits/stdc++.h>

const int N = 100010;

int a[N];
int n, k;

void solve(int l, int r){
	if (l == r - 1) return;
	if (k <= 0) return;
	k -= 2;
	int mid = l + r >> 1;
	solve(l, mid);
	solve(mid, r);
	if (!k || l == r - 2){
		for (int i = l; i < mid; ++ i){
			std::swap(a[i], a[i + mid - l]);
		}
		if (!k) k -= 2;
	}
}

int main(){
	scanf("%d%d", &n, &k);
	if (2 * n - 1 < k || k % 2 == 0){
		return printf("-1\n"), 0;
	}
	for (int i = 0; i < n; ++ i){
		a[i] = i + 1;
	}
	-- k;
	solve(0, n);
	for (int i = 0; i < n; ++ i){
		printf("%d%c", a[i], " \n"[i == n - 1]);
	}
	return 0;
}