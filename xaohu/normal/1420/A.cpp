#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
	int t;
	scanf ("%d", &t);
	while (t--) {
		int n;
		scanf ("%d", &n);
		vector <int> a(n);
		for (auto &x: a)
			scanf ("%d", &x);
		bool q = 1;
		for (int i = 1; i < n; ++i)
			q &= a[i - 1] > a[i];
		if (q) printf ("NO");
		else printf ("YES");
		puts("");
	}
}