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

const ll M = 1000000007;

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
vector<vector<ll>> mul(vector<vector<ll>> a,vector<vector<ll>> b,int n){
	ll i,j,k,t;
	vector<vector<ll>> c(n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			t = 0;
			for (k = 0; k < n; k++)
				t = (t + a[i][k]*b[k][j] % (M - 1))%(M-1);
			c[i].push_back(t);
		}
	}
	return c;
}
int main() {
	ll f1, f2, f3, n, c,ans=1,cn,cp,i,j;
	cin >> n >> f1 >> f2 >> f3 >> c;
	vector<vector<ll>> a{ {0,1,0},{0,0,1},{1,1,1} };
	vector<vector<ll>> b{ {1,0,0},{0,1,0},{0,0,1} };
	cn = n - 3;
	while (cn > 0) {
		if (cn % 2 == 1)
			b = mul(a, b,3);
		a = mul(a, a, 3);
		cn /= 2;
	}
	cp = b[2][0];
	while (cp > 0) {
		if (cp % 2 == 1)
			ans = ans * f1%M;
		f1 = f1 * f1%M;
		cp /= 2;
	}
	cp = b[2][1];
	while (cp > 0) {
		if (cp % 2 == 1)
			ans = ans * f2%M;
		f2 = f2 * f2%M;
		cp /= 2;
	}
	cp = b[2][2];
	while (cp > 0) {
		if (cp % 2 == 1)
			ans = ans * f3%M;
		f3 = f3 * f3%M;
		cp /= 2;
	}
	vector<vector<ll>> e{ {0,1,0,0,0},{0,0,1,0,0},{1,1,1,2,0},{0,0,0,1,1},{0,0,0,0,1} };
	vector<vector<ll>> d{ {1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1} };
	cn = n - 3;
	while (cn > 0) {
		if (cn % 2 == 1)
			d = mul(e,d, 5);
		e = mul(e, e, 5);
		cn /= 2;
	}
	cp = (d[2][3]+d[2][4])%(M-1);
	while (cp > 0) {
		if (cp % 2 == 1)
			ans = ans * c%M;
		c = c * c%M;
		cp /= 2;
	}
	cout << ans << endl;
}