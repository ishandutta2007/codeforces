#include <bits/stdc++.h>
using namespace std;

int n, a;

void solve(int n) {
	a = (n + 1) / 3;
	set <int> S;
	for(int i = 1; i <= n; ++ i) {
		if(i % 3 == 1) continue;
		S.insert(i);
	}
	while(S.size() > 1) {
		int l = *S.begin(), r = *S.rbegin();
		printf("%d %d\n", l, r);
		printf("%d %d\n", r, l);
		S.erase(l); 
		S.erase(r);
	}
	printf("%d %d\n", *S.begin(), *S.begin());
}

int main() {
	scanf("%d", &n);
	if(n == 1) {
		puts("1");
		puts("1 1");
		return 0;
	}
	if(n == 2) {
		puts("1");
		puts("1 1");
		return 0;
	}
	if(n == 3) {
		puts("2");
		puts("1 2");
		puts("1 1");
		return 0;
	}
	printf("%d\n", n - (n + 1) / 3);
	int now = (n + 1) % 3;
	solve(n - now);
	if(now >= 1)
	printf("%d %d\n", n - now + 1, n - now + 1);
	if(now >= 2) 
	printf("%d %d\n", n - now + 2, n - now + 2);
}