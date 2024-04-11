#include <bits/stdc++.h>
using namespace std;
int n, v, b, c;
long long k;
int main() {
	cin >> n >> k;
	for (int i = 0; i < n && c < k; i++) {
		cin >> v;
		c = b > 0 ? (b > v ? c + 1 : 1) : 0;
		b = max(b, v);
	}
	printf("%d\n", b);
}