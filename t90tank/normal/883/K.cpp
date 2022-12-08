#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

const int mxn = 200006;
const int mxs = 2000006;

int n;
int s[mxn];
int g[mxn];

int d[mxn];
vi st[mxs];

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &s[i], &g[i]);
		st[s[i] + g[i]].pb(i);
	}
	
	for (int i = 1; i <= 2000000; ++i) {
		for (auto j : st[i])
			if (!d[j]) {
				d[j] = i;
				if (j - 1 >= 1) st[i + 1].pb(j - 1);
				if (j + 1 <= n) st[i + 1].pb(j + 1);
			}
		st[i] = {};
	}
	
	for (int i = 1; i <= n; ++i)
		if (!(s[i] <= d[i])) {
			puts("-1");
			return 0;
		}
	
	ll sum = 0;
	for (int i = 1; i <= n; ++i)
		sum += d[i] - s[i];
	
	cout << sum << endl;
	for (int i = 1; i <= n; ++i)
		printf("%d ", d[i]);
	puts("");
	
	return 0;
}