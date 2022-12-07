#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

const int N = 2e5 + 10;
const int B = 300;

int n, q, jmp[N];
ll f[N], sum[N];

int id(int x) {
	return x / B;
}

int nxt(int x) {
	return max(0ll, f[x] - sum[id(x)]);
}

void calc(int x) {
	if (sum[x] > B)
		return;
	rep(i, B * x, B * (x + 1)) {
		int j = nxt(i);
		if (B * x <= j)
			jmp[i] = jmp[j];
		else
			jmp[i] = i;
	}
}			

int go(int x) {
	if (nxt(x) >= B * id(x))
		return jmp[x];
	return x;
}

int main() {
	cin >> n >> q;
	rep(i, 1, n)
		cin >> f[i], f[i]--;
	rep(i, 0, id(n - 1) + 1)
		calc(i);
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			l--; r--;
			int a = id(l);
			int b = id(r);
			while (id(l) == a && l <= r) 
				f[l++] -= x;
			while (id(r) == b && l <= r)
				f[r--] -= x;
			rep(i, a + 1, b)
				sum[i] += x;
			rep(i, a, b + 1)
				calc(i);
		}
		else {
			int a, b;
			cin >> a >> b;
			a--; b--;
			while (a != b) {
				if (a > b) swap(a, b);
				if (id(a) != id(b) || go(a) != go(b)) {
					b = nxt(go(b));
					continue;
				}
				b = nxt(b);
			}
			cout << a + 1 << endl;
		}
	}
	return 0;
}