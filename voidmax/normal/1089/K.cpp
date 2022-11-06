#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define len(v) ((int)v.size())

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
	for (T x : v) {
		os << x << " ";
	}
	return os;
}

template <class T>
istream &operator>>(istream &is, vector<T> &v) {
	for (T &x : v) {
		is >> x;
	}
	return is;
}

void run();

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	run();
}

const int N = 1 << 20;

struct seg_tree {
	long long mod[N * 2 + 1];
	long long t[N * 2 + 1];

	long long chg(int i, int L, int R, int Ln, int Rn, int v) {
		if (Ln <= L && R <= Rn) {
			mod[i] += v;
			return t[i] + mod[i];
		}
		if (Rn <= L || R <= Ln) {
			return t[i] + mod[i];
		}	
		int M = (L + R) >> 1;
		t[i] = max(chg(i * 2, L, M, Ln, Rn, v), chg(i * 2 + 1, M, R, Ln, Rn, v));
		return t[i] + mod[i];
	}

	long long get(int i, int L, int R, int Ln, int Rn) {
		if (Ln <= L && R <= Rn) {
			return t[i] + mod[i];
		}
		if (Rn <= L || R <= Ln) {
			return -4e18;
		}
		int M = (L + R) >> 1;
		return max(get(i * 2, L, M, Ln, Rn), get(i * 2 + 1, M, R, Ln, Rn)) + mod[i];
	}
} box;

int n;
int t[N + 1], w[N + 1];
long long sum_all;
bool have[N + 1];

void run() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		char c;
		cin >> c;
		if (c == '?') {
			int v;
			cin >> v;
			long long rest = box.get(1, 0, N, v + 1, v + 2);			
			// cout << "?" << rest << endl;
			// cout << "?" << rest << ' ' << box.t[1] << ' ' << v << endl;
			if (have[v + 1]) rest -= v + 1;
			// cout << "?" << rest << endl;
			// rest = sum_all - rest;
			long long ans = box.get(1, 0, N, 0, v + 1);
			// cout << ans << "!" << rest << endl;
			cout << max(0LL, ans - rest - v) << '\n';
		} else if (c == '+') {
			cin >> t[i] >> w[i];
			sum_all += w[i];
			have[t[i]] = true;
			box.chg(1, 0, N, 0, t[i] + 1, w[i]);
			box.chg(1, 0, N, t[i], t[i] + 1, t[i]);
		} else {
			int j;
			cin >> j;
			sum_all -= w[i];
			have[t[j]] = false;
			box.chg(1, 0, N, 0, t[j] + 1, -w[j]);
			box.chg(1, 0, N, t[j], t[j] + 1, -t[j]);
		}
	}
}