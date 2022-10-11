#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> frac;

int n;
int a, b;
vector<frac> O, V;

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

frac reduce(frac o) {
	int g = gcd(o.first, o.second);
	return {o.first / g, o.second / g};
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		char d;
		scanf(" %c%d%c%d%c%c%d", &d, &a, &d, &x, &d, &d, &b);
		a += x;
		frac r = reduce({a, b});
		O.push_back(r);
		V.push_back(r);
	}

	sort(V.begin(), V.end());
	for (int i = 0; i < n; ++i) {
		printf("%d ", upper_bound(V.begin(), V.end(), O[i]) - lower_bound(V.begin(), V.end(), O[i]));
	}
	printf("\n");
}