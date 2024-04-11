#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
const int maxn = 100010;
const double eps = 1e-8;
typedef long long ll;
int n;
ll k, a[maxn];
char str[12];
bool p[maxn], all;
int main() {
	scanf("%d%I64d", &n, &k);
	all = true;
	for (int i = 0; i <= n; ++i) {
		scanf("%s", str);
		if (str[0] == '?') p[i] = true, all = false;
		else {
			int m = strlen(str);
			if (str[0] == '-') {
				for (int j = 1; j < m; ++j)
					a[i] = a[i] * 10 + str[j] - '0';
				a[i] = -a[i];
			}
			else {
				for (int j = 0; j < m; ++j)
					a[i] = a[i] * 10 + str[j] - '0';
			}
		}
	}
	if (k == 0) {
		if (!p[0]) {
			if (a[0] == 0) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else {
			int now = 0;
			for (int i = 0; i <= n; ++i)
				if (!p[i]) ++now;
			if (now % 2 == 0) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}
	else {
		if (all) {
			bool can = true;
			for (int i = 0; i < n; ++i) {
				if (a[i] % k != 0) {
					can = false; break;
				}
				a[i + 1] += a[i] / k;
			}
			if (a[n]) can = false;
			if (can) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else {
			if (n % 2 == 0) cout << "No" << endl;
			else cout << "Yes" << endl;
		}
	}
}