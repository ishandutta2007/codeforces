#include <iostream>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

const int MAX_N = 2e5 + 7, M = 998244353;

int fact[MAX_N], perm[MAX_N], lleft[MAX_N], f[MAX_N];
bool used[MAX_N];
vector <int> freee;

int fast_pow(int n, int p) {
	if (p == 0) return 1;
	if (p == 1) return n;
	if (p % 2 == 0) {
		int m = fast_pow(n, p / 2);
		return (m * m) % M;
	}
	return (fast_pow(n, p - 1) * n) % M;
}

int obr(int x) {
	return fast_pow(x, M - 2);
}

void update(int pos) {
	for (int i = pos; i < MAX_N; i += i & (-i)) f[i]++;
}

int get(int pos) {
	int ans = 0;
	for (int i = pos; i >= 1; i -= i & (-i)) ans += f[i];
	return ans;
}

void init() {
	fact[0] = 1;
	for (int i = 1; i < MAX_N; i++) {
		fact[i] = (fact[i - 1] * i) % M;
		f[i] = 0;
		used[i] = 0;
	}
}

pair <int, int> find_less_more(int x) {
	auto uk = lower_bound(freee.begin(), freee.end(), x);
	int res = uk - freee.begin();
	return make_pair(res, (int) freee.size() - res);
}

signed main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	init();
	int n;
	cin >> n;
	lleft[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> perm[i];
		if (perm[i] != -1) used[perm[i]] = 1;
		lleft[i] = lleft[i - 1];
		if (perm[i] == -1) lleft[i]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!used[i]) freee.push_back(i);
	}
	int ans = 0;
	int cnt_free = freee.size();
	int inside = (((((fact[cnt_free] * cnt_free) % M) * (cnt_free - 1)) % M) * obr(4)) % M;
	int outside = 0;
	int cc = 0;
	for (int i = 1; i <= n; i++) {
		if (perm[i] == -1) continue;
		outside += (cc - get(perm[i]));	
		update(perm[i]);
		cc++;
	}
	outside = (outside * fact[cnt_free]) % M;
	ans = (inside + outside) % M;
	int both = 0;
	for (int i = 1; i <= n; i++) {
		if (perm[i] == -1) continue;
		pair <int, int> now = find_less_more(perm[i]);
		int a = now.first, b = now.second;
		int l = lleft[i], r = cnt_free - l;
		both = (both + ((a * r) % M) * fact[cnt_free - 1]) % M;
		both = (both + ((b * l) % M) * fact[cnt_free - 1]) % M;
	}
	ans = (ans + both) % M;
	int q = obr(fact[cnt_free]);
	cout << (ans * q) % M << endl;
	return 0;
}