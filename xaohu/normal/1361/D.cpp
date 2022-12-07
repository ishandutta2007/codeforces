#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define double long double
typedef long long ll;
using namespace std;

int n, k, id;
map<pair<ll, ll>, int> m;
vector<double> v[500000];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		if (!x && !y)
			continue;
		ll g = __gcd(abs(x), abs(y));
		ll a = x / g;
		ll b = y / g;
		if (m.count(make_pair(a, b)) == 0)
			m[make_pair(a, b)] = id++;
		v[m[make_pair(a, b)]].push_back(sqrt(x * x + y * y));
	}

	for (int i = 0; i < id; i++)
		sort(v[i].begin(), v[i].end(), greater<double>());

	vector<double> q;
	for (int i = 0; i < id; i++) {
		for (int j = 0; j < v[i].size(); j++)
			q.push_back(v[i][j] * (k - 1 - 2 * j));
	}
	sort(q.begin(), q.end(), greater<double>());
	double res = accumulate(q.begin(), q.begin() + min(k, (int)q.size()), 0.0);

	for (int i = 0; i < id; i++)
		if (v[i].size() >= n - k + k / 2) {
			double cur = 0;
			for (int j = 0; j < id; j++)
				if (i != j) {
					for (int a = 0; a < v[j].size(); a++)
						cur += v[j][a] * (k - 1 - 2 * a);
				}
			for (int j = 0; j < k / 2; j++)
				cur += v[i][j] * (k - 1 - 2 * j);
			int s = n - k + k / 2;
			for (int j = s; j < v[i].size(); j++)
				cur += v[i][j] * (k - 1 - 2 * (k / 2 + j - s));
			res = max(res, cur);
		}

	cout << setprecision(20) << res << endl;
	return 0;
}