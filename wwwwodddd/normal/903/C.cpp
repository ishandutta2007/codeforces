#include <bits/stdc++.h>
using namespace std;
int n, x, z;
map<int, int> g;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		g[x]++;
	}
	for (pair<int, int> i: g) {
		z = max(z, i.second);
	}
	printf("%d\n", z);
}