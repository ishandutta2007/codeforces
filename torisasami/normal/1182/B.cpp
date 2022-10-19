#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<list>
#include<set>
#include<string>
using namespace std;
int gcd(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}
struct UnionFind {
	vector<int> par; // par[i]:i() par[3] = 2 : 32

	UnionFind(int N) : par(N) { //
		for (int i = 0; i < N; i++) par[i] = i;
	}

	int root(int x) { // xroot(x) = {x}
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}

	void unite(int x, int y) { // xy
		int rx = root(x); //xrx
		int ry = root(y); //yry
		if (rx == ry) return; //xy(=)
		par[rx] = ry; //xy(=)xrxyry
	}

	bool same(int x, int y) { // 2x, ytrue
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
};
typedef long long ll;

const ll M = 998244353;

vector<ll> fac(300001); //n!(mod M)
vector<ll> ifac(300001); //k!^{M-2} (mod M)

ll mpow(ll x, ll n) {
	ll ans = 1;
	while (n != 0) {
		if (n & 1) ans = ans * x % M;
		x = x * x % M;
		n = n >> 1;
	}
	return ans;
}
ll comb(ll a, ll b) {
	if (a == 0 && b == 0)return 1;
	if (a < b || a < 0)return 0;
	ll tmp = ifac[a - b] * ifac[b] % M;
	return tmp * fac[a] % M;
}
// mod. m  a  a^{-1} 
long long modinv(long long a) {
	long long b = M, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= M;
	if (u < 0) u += M;
	return u;
}
int main() {
	ll i, j, w, h,c,flag1=0,flag2=0,px,py,l,r,u,d;
	char s[555][555];
	cin >> h >> w;
	for (i = 0; i < h; i++)
		cin >> s[i];
	for (i = 0; i < h; i++) {
		c = 0;
		for (j = 0; j < w; j++)
			if (s[i][j] == '*')
				c++;
		if (flag1 != -1) {
			if (c == 2)
				flag1 = -1;
			else if (c > 2) {
				if (flag1 == 0) {
					py = i;
					flag1 = 1;
				}
				else
					flag1 = -1;
			}
		}
	}
	for (j = 0; j < w; j++) {
		c = 0;
		for (i = 0; i < h; i++)
			if (s[i][j] == '*')
				c++;
		if (flag2 != -1) {
			if (c == 2)
				flag2 = -1;
			else if (c > 2) {
				if (flag2 == 0) {
					px = j;
					flag2 = 1;
				}
				else
					flag2 = -1;
			}
		}
	}
	if (flag1 != 1 || flag2 != 1) {
		cout << "NO" << endl;
		return 0;
	}
	flag1 = 0;
	for (i = 0; i < h; i++) {
		if (s[i][px] == '*'&&flag1 == 0) {
			u = i;
			flag1++;
		}
		else if (s[i][px] == '.'&&flag1 == 1) {
			d = i - 1;
			flag1 = -1;
		}
	}
	if (flag1 == 1)
		d = h - 1;
	flag1 = 0;
	for (j = 0; j < w; j++) {
		if (s[py][j] == '*'&&flag1 == 0) {
			l = j;
			flag1++;
		}
		else if (s[py][j] == '.'&&flag1 == 1) {
			r = j - 1;
			flag1 = -1;
		}
	}
	if (flag1 == 1)
		r = w - 1;
	if (!(l < px&&px < r&&u < py&&py < d)) {
		cout << "NO" << endl;
		return 0;
	}
	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (!((i == py && l <= j && j <= r) || (j == px && u <= i && i <= d))) {
				if (s[i][j] == '*') {
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}
	cout << "YES" << endl;
}