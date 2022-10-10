#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

typedef double ld;

const ld PI = acos(-1);

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

const int ms = 1 << 20;

int bits[ms];
Complex root[ms];

void initFFT() {
	root[1] = Complex(1);
	for(int len = 2; len < ms; len += len) {
		Complex z(cos(PI / len), sin(PI / len));
		for(int i = len / 2; i < len; i++) {
			root[2 * i] = root[i];
			root[2 * i + 1] = root[i] * z;
		}
	}
}

void pre(int n) {
	int LOG = 0;
	while(1 << (LOG + 1) < n) {
		LOG++;
	}
	for(int i = 1; i < n; i++) {
		bits[i] = (bits[i >> 1] >> 1) | ((i & 1) << LOG);
	}
}


CVector fft(CVector a, bool inv = false) {
	int n = a.size();
	pre(n);
	if(inv) {
		std::reverse(a.begin() + 1, a.end());
	}
	for(int i = 0; i < n; i++) {
		int to = bits[i];
		if(to > i) {
			std::swap(a[to], a[i]);
		}
	}
	for(int len = 1; len < n; len *= 2) {
		for(int i = 0; i < n; i += 2 * len) {
			for(int j = 0; j < len; j++) {
				Complex u = a[i + j], v = a[i + j + len] * root[len + j];
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

std::vector<int> mul(const std::vector<int> &a, const std::vector<int> &b) {
	int n = (int) a.size();
	CVector poly(n);
	for(int i = 0; i < n; i++) {
		if(i < (int) a.size()) {
			poly[i].real = a[i];
		}
		if(i < (int) b.size()) {
			poly[i].imag = b[i];
		}
	}
	poly = fft(poly);
	for(int i = 0; i < n; i++) {
		poly[i] *= poly[i];
	}
	poly = fft(poly, true);
	std::vector<int> c(n, 0);
	for(int i = 0; i < n; i++) {
		c[i] = (int) (poly[i].imag / 2 + 0.5);
	}
	//while (c.size() > 0 && c.back() == 0) c.pop_back();
	return c;
}


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	initFFT();
	int n, x, y;
	std::cin >> n >> x >> y;
	std::vector<int> a(ms, 0), b(ms, 0);
	for(int i = 0; i <= n; i++) {
		int pos;
		std::cin >> pos;
		a[pos]++;
		b[(ms-pos)%ms]++;
	}
	a = mul(a, b);
	std::vector<int> c(ms, -1);
	for(int i = 1; i < ms/2; i++) {
		if(a[i]) {
			c[2*i+2*y] = 2*i+2*y;
		}
	}
	for(int i = 2; i < ms; i += 2) {
		for(int j = i; j < ms; j += i) {
			c[j] = std::max(c[j], c[i]);
		}
	}
	int q;
	std::cin >> q;
	while(q--) {
		int pos;
		std::cin >> pos;
		std::cout << c[pos] << (q == 0 ? '\n' : ' ');
	}
}