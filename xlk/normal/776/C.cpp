#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n;
long long k;
map<long long, int>g;
long long a[100020];
int main() {
	cin >> n >> k;
	long long s = 0;
	g[s] += 1;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		s += a[i];
		for (long long c = 1; c <= 1e16;) {
			ans += g[s - c];
			c *= k;
			if (c == 1) {
				break;
			}
		}
		g[s] += 1;
	}
	cout << ans << endl;
	return 0;
}