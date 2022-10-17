#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int T = 12;
const int MX = 12;
mt19937 rnd(time(0));
pair<int, vector<int>> gen() {
	int n = T;
	vector<int> a(n);
	for (auto &it : a) {
		it = rnd() % MX;
		if (rnd() & 1) {
			it *= -1;
		}
	}
	return make_pair(n, a);
}

int slow_solve(int n, vector<int> a) {
	int res = n * n;
	for (int i = 0; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int vl1 = a[j], vl2 = a[k];
				if ((i >> j) & 1) {
					vl1 *= -1;
				}
				if ((i >> k) & 1) {
					vl2 *= -1;
				}
				if (vl1 > vl2) {
					sum++;
				}
			}
		}
		res = min(res, sum);
	}
	return res;
}

int fast_solve(int n, vector<int> a) {
	for (int i = 0; i < n; i++) {
		int sum1 = 0, sum2 = 0;
		a[i] = abs(a[i]);
		for (int j = 0; j < i; j++) {
			if (a[j] > a[i]) {
				sum1++;
			}
			if (a[j] > -a[i]) {
				sum2++;
			}
		}
		for (int j = i + 1; j < n; j++) {
			if (abs(a[j]) < a[i]) {
				sum1++;
			}
		}
		if (sum1 >= sum2) {
			a[i] = -a[i];
		}		
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[i]) {
				res++;
			}
		}
	}	
	return res;
}

void stress() {
	for (int i = 0; i < 200; i++) {
		pair<int, vector<int>> kek = gen();
		int ans1 = slow_solve(kek.F, kek.S), ans2 = fast_solve(kek.F, kek.S);
		if (ans1 != ans2) {
			cout << "ERROR\n" << "TEST: \n" << kek.F << '\n';
			for (auto it : kek.S) {
				cout << it << ' ';
			} 
			cout << '\n';
			cout << "CORRECT ANSWER: " << ans1 << '\n';
			cout << "MY ANSWER: " << ans2 << '\n';
			exit(0); 
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	//stress();
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &it : a) {
		cin >> it;
	}
	cout << fast_solve(n, a) << '\n';
	//cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}