#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
typedef double ld;
const int md = 998244353, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acosl(-1);
const ldb PI = pi;
using namespace std;

const int maxn = (1 << 20) + 5;

struct Complex {
	ld real, imag;
	Complex conj() { return Complex(real, -imag); }
	Complex(ld a = 0, ld b = 0) : real(a), imag(b) {}
	Complex operator + (const Complex &o) const { return Complex(real + o.real, imag + o.imag); }
	Complex operator - (const Complex &o) const { return Complex(real - o.real, imag - o.imag); }
	Complex operator * (const Complex &o) const { return Complex(real * o.real - imag * o.imag, real * o.imag + imag * o.real); }
	Complex operator / (ld o) const { return Complex(real / o, imag / o); }
	void operator *= (Complex o) { *this = *this * o; }
	void operator /= (ld o) { real /= o, imag /= o; }
};

typedef std::vector<Complex> CVector;

int bits[1 << 21];

void pre(int n) {
	int LOG = 0;
	while(1 << (LOG + 1) < n) {
		LOG++;
	}
	for(int i = 1; i < n; i++) {
		bits[i] = (bits[i >> 1] >> 1) | ((i & 1) << LOG);
	}
}

Complex root[1 << 21];

CVector fft(CVector a, bool inv = false) {
	int n = a.size();
	pre(n);
	for(int i = 0; i < n; i++) {
		int to = bits[i];
		if(to > i) {
			std::swap(a[to], a[i]);
		}
	}
	
	double angle = inv ? -PI : PI;
	for(int len = 1; len < n; len *= 2) {
		for(int i = 0; i < len; i++) {
			root[i] = Complex(cos(angle / len * i), sin(angle / len * i));
		}
		for(int i = 0; i < n; i += 2 * len) {
			for(int j = 0; j < len; j++) {
				Complex cur_root = root[j];
				Complex u = a[i + j], v = a[i + j + len] * cur_root;
				a[i + j] = u + v;
				a[i + j + len] = u - v;
			}
		}
	}
	if(inv) {
		for(int i = 0; i < n; i++)
			a[i] /= n;
	}
	return a;
}

void fft2in1(CVector &a, CVector &b) {
	int n = (int) a.size();
	for(int i = 0; i < n; i++) {
		a[i] = Complex(a[i].real, b[i].real);
	}
	auto c = fft(a);
	for(int i = 0; i < n; i++) {
		a[i] = (c[i] + c[(n-i) % n].conj()) * Complex(0.5, 0);
		b[i] = (c[i] - c[(n-i) % n].conj()) * Complex(0, -0.5);
	}
}

void ifft2in1(CVector &a, CVector &b) {
	int n = (int) a.size();
	for(int i = 0; i < n; i++) {
		a[i] = a[i] + b[i] * Complex(0, 1);
	}
	a = fft(a, true);
	for(int i = 0; i < n; i++) {
		b[i] = Complex(a[i].imag, 0);
		a[i] = Complex(a[i].real, 0);
	}
}

CVector C[4];

std::vector<int> mul(const std::vector<int> &a, const std::vector<int> &b, long long cut = 1 << 16) {
	int n = (int) a.size();
	for(int i = 0; i < 4; i++) {
		C[i].resize(n);
	}
	for(int i = 0; i < n; i++) {
		C[0][i] = a[i] % cut;
		C[1][i] = a[i] / cut;
		C[2][i] = b[i] % cut;
		C[3][i] = b[i] / cut;
	}
	fft2in1(C[0], C[1]);
	fft2in1(C[2], C[3]);
	for(int i = 0; i < n; i++) {
		// 00, 01, 10, 11
		Complex cur[4];
		for(int j = 0; j < 4; j++) cur[j] = C[j/2+2][i] * C[j % 2][i];
		for(int j = 0; j < 4; j++) C[j][i] = cur[j];
	}
	ifft2in1(C[0], C[1]);
	ifft2in1(C[2], C[3]);
	std::vector<int> ans(n, 0);
	for(int i = 0; i < n; i++) {
		// if there are negative values, care with rounding
		ans[i] += (long long) (C[0][i].real + 0.5) % md;
		ans[i] %= md;
		ans[i] += (long long) (C[1][i].real + C[2][i].real + 0.5) * cut % md;
		ans[i] %= md;
		ans[i] += (long long) (C[3][i].real + 0.5) * cut % md * cut % md;
		ans[i] %= md;
	}
	return ans;
}

vector<int> p1, p2;

void mult(vector<int> &a, const vector<int> &b) {
	int n = a.size() + b.size();
	while (n != (n & -n)) n += (n & -n);
	p1.resize(0);
	p2.resize(0);
	for (auto &i : a) p1.push_back(i);
	for (auto &i : b) p2.push_back(i);
	while (p1.size() < n) p1.push_back(0);
	while (p2.size() < n) p2.push_back(0);
	a = mul(p1, p2, (long long)(1 << 15));
	while (a.size() && a.back() == 0) a.pop_back();
}

vector<int> pw(vector<int> a, int e) {
	vector<int> rtn = { 1 };
	while (e) {
		if (e & 1) mult(rtn, a);
		e /= 2;
		if(e) mult(a, a);
	}
	return rtn;
}

int n, k;
vector<int> a(10, 0);

int main() {
	fast;
	cin >> n >> k;
	int x;
	for (int i = 0; i < k; i++) {
		cin >> x;
		a[x] = 1;
	}
	vector<int> A = pw(a, n / 2);
	int ans = 0;
	for (auto &i : A) {
		ans = (ans + (ll)i * i) % md;
	}
	finish(ans);
}