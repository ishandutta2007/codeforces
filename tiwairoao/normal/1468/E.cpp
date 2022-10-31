#include <bits/stdc++.h>

int a[4];

void solve() {
	for(int i=0;i<4;i++) scanf("%d", &a[i]); std::sort(a, a + 4);
	
	int ans = 0;
	do {
		ans = std::max(ans, std::min(a[0], a[1]) * std::min(a[2], a[3]));
	}while( std::next_permutation(a, a + 4) );
	printf("%d\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}