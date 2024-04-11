// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
#include <bits/stdc++.h>
#define x first 
#define y second
#define pb push_back
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define files(FILENAME) read(FILENAME), write(FILENAME)
using namespace std;

template <typename T1, typename T2> inline void chkmin(T1 &x, T2 y) {if (x > y) x = y;} 
template <typename T1, typename T2> inline void chkmax(T1 &x, T2 y) {if (x < y) x = y;} 

const string FILENAME = "input";
typedef pair<int, int> point;

const int MAXN = 1 << 18;

int arr[MAXN];

struct seg_tree {
	int a[MAXN * 2];
	int mod[MAXN * 2];

	void init() {
		for (int i = 0; i < MAXN; ++i) {
			a[i + MAXN] = arr[i];
		}
		for (int i = 0; i < MAXN * 2; ++i)
			mod[i] = 0;
		for (int i =  MAXN; i--;) {
			a[i] = a[i * 2] + a[i * 2 + 1];
		}
	}

	void push(int i) {
		if (i < MAXN) {
			if (a[i * 2] >= mod[i]) {
				a[i * 2] -= mod[i];
				mod[i * 2] += mod[i];
			} else {
				mod[i * 2] += a[i * 2];
				mod[i * 2 + 1] += mod[i] - a[i * 2];
				a[i * 2 + 1] -= mod[i] - a[i * 2];
				a[i * 2] = 0;
			}
		}
		mod[i] = 0;
	}

	int Ln, Rn, k;

	void get(int i, int L, int R) {
		if (!k) return;
		push(i);
		if (Ln <= L && R <= Rn) {
			int ans = min(k, a[i]);
			mod[i] += ans;
			a[i] -= ans;
			k -= ans;
			return;
		}
		if (Rn <= L || R <= Ln || !k) {
			return;
		}
		int M = (L + R) >> 1;
		get(i * 2, L, M);
		get(i * 2 + 1, M, R);
		a[i] = a[i * 2] + a[i * 2 + 1];
	}

	bool can(int L, int R, int nk) {
		Ln = L;
		Rn = R;
		k = nk;
		get(1, 0, MAXN);
		return k == 0;
	}
};

int p, n, d, b;
long long f[MAXN];
vector<int> que[2];
long long L[MAXN], R[MAXN];
bool need[MAXN];
vector<int> q;

bool cmp(int i, int j) {
	if (R[i] == R[j]) {
		return L[i] < L[j];
	}
	return R[i] < R[j];
}

seg_tree box;

bool check(int M) {
	box.init();
	for (int i = 0; i < n; ++i) need[i] = false;
	for (int i = M; i < que[0].size(); ++i) need[que[0][i]] = true;
	for (int i = M; i < que[1].size(); ++i) need[que[1][i]] = true;
	for (auto i : q) {
		if (need[i]) {
			if (!box.can(L[i], R[i], b)) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	//read(FILENAME);
	cin >> n >> d >> b;
	p = 2;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	if (p == 1) {
		for (int i = 0; i < n; ++i) {
			f[i] = i + 1;
			que[0].pb(i);
		}
	} else if (p == 2) {
		int t = 1, L = 0, R = n - 1;
		while (L <= R) {
			que[0].pb(L);
			f[L] = t;
			if (L != R) {
				que[1].pb(R);
				f[R] = t;
			}
			++t;
			++L, --R;
		}
	}
	for (int i = 0; i < n; ++i) {
		L[i] = i - f[i] * d;
		chkmax(L[i], 0);
		R[i] = i + f[i] * d + 1;
		chkmin(R[i], n);
		q.pb(i);
	}
	sort(q.begin(), q.end());
	int L = -1, R = n;
	while (R - L > 1) {
		int M = (L + R) >> 1;
		if (check(M)) {
			R = M;
		} else {
			L = M;
		}
	}
	cout << R << endl;
}