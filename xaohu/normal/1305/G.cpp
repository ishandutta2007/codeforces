#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

const int N = 1 << 20;

int n, cnt[N], p[N];
ll res;

int find(int x) {
	if (p[x] < 0)
		return x;
	return p[x] = find(p[x]);
}

int join(int a, int b) {
	if (!cnt[a] || !cnt[b]) return 0;
	a = find(a);
	b = find(b);
	if (a == b) return 0;
	int sz = (p[a] == -1 ? cnt[a] : 1) + (p[b] == -1 ? cnt[b] : 1);
	p[b] += p[a];
	p[a] = b;
	return sz - 1;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	rep(i, 0, n) {
		int x;
		cin >> x;
		cnt[x]++;
		res -= x;
	}
	cnt[0]++;

	memset(p, -1, sizeof p);
	per(mask, 0, (1 << 18))
		for (int sub = mask;; sub = ((sub - 1) & mask)) {
			res += 1ll * mask * join(sub, mask - sub);
			if (sub == 0)
				break;
		}
	cout << res << endl;
	return 0;
}