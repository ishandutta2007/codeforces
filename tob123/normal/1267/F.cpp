#include <bits/stdc++.h>
using namespace std;

#define Debug(x) x
typedef int regular_int;
// #define int ll
typedef long long ll;

int cnt[300000];


regular_int main() {
	ios_base::sync_with_stdio(false);
	cout << setprecision(12) << fixed;

	int n, m, a, b;
	cin >> n >> m >> a >> b;
	if(a > m - 1 || b > n - 1) {
		cout << "NO" << endl;
		return 0;
	}
	set <int > active;
	vector<int > x(m - 1, 1), y(n - 1, n + 1);
	for(int i = 0; i < a; ++i) {
		cin >> x[m - 2 - i];
	}
	for(int i = 0; i < b; ++i) {
		cin >> y[n - 2 - i];
	}
	for(int i = 0; i < n + m; ++i) {
		active.insert(i + 1);
	}
	for(int i = 0; i < m - 1; ++i) {
		active.erase(x[i]);
		++cnt[x[i]];
	}
	for(int i = 0; i < n - 1; ++i) {
		active.erase(y[i]);
		++cnt[y[i]];
	}
	cout << "YES" << endl;
	while(!x.empty() || !y.empty()) {
		int z = *active.begin(), p;
		if(z <= n) {
			p = y.back();
			y.pop_back();
		} else {
			p = x.back();
			x.pop_back();
		}
		cout << z << " " << p << "\n";
		active.erase(z);
		--cnt[p];
		if (!cnt[p]){
            active.insert(p);
		}

	}
    int z = *active.begin();
    active.erase(z);
    int p = *active.begin();
    cout << z << " " << p << endl;


	return 0;
}