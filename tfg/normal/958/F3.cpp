#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <queue>
#include <algorithm>
#include <utility>

typedef std::pair<int, std::vector<int> > vi;

using namespace std;

typedef double ld;

const ld PI = acosl(-1.0);
const int ms = 1 << 20;

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

std::vector<int> mult(std::vector<int> a, std::vector<int> b) {
	int s = 1;
	while(s < a.size() + b.size() - 1) s += s;
	a.resize(s, 0);
	b.resize(s, 0);
	CVector temp(s, 0);
	pre(s);
	for(int i = 0; i < s; i++) {
		temp[i] = Complex(a[i], b[i]);
	}
	temp = fft(temp);
	for(int i = 0; i < s; i++) {
		temp[i] *= temp[i];
	}
	temp = fft(temp, true);
	std::vector<int> ans(s, 0);
	for(int i = 0; i < s; i++) {
		ans[i] = (long long)(temp[i].imag / 2 + 0.5) % 1009;
	}
	while(!ans.empty() && ans.back() == 0) ans.pop_back();
	return ans;
}

int freq[ms];

int main() {
    initFFT();
	int n, m, k;
	std::cin >> n >> m >> k;
	for(int i = 0; i < n; i++) {
		int t;
		std::cin >> t;
		freq[t]++;
	}
	std::priority_queue<vi, std::vector<vi>, std::greater<vi> > hp;
	for(int i = 0; i <= m; i++) {
		if(freq[i]) {
			vi cur(freq[i] + 1, std::vector<int>(freq[i] + 1, 1));
			hp.push(cur);
		}
	}
	while(hp.size() > 1) {
		auto v = hp.top().second;
		hp.pop();
		v = mult(v, hp.top().second);
		hp.pop();
		hp.push(vi(v.size(), v));
	}
	std::cout << hp.top().second[k] << std::endl;
}