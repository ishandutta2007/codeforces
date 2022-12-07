#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

int n, k, cnt[111000];
ll a[111000], res;
priority_queue<pair<ll, int>> q;

ll cost(ll x, ll d) {
	ll f = x / d;
	ll r = x % d;
	return (d - r) * f * f + r * (f + 1) * (f + 1);
}

void add(int i) {
	cnt[i]++;
	q.push({cost(a[i], cnt[i]) - cost(a[i], cnt[i] + 1), i});
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> k;
	rep(i, 0, n) {
		cin >> a[i];
		res += a[i] * a[i];
		add(i);
	}

	k -= n;
	while (k--) {
		auto [c, id] = q.top();
		q.pop();
		res -= c;
		if (cnt[id] < a[id])
			add(id);
	}
	cout << res << endl;

	return 0;
}