#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-5
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

namespace bigint {
	// multiprecision integers

struct comp {
	dbl x, y;
	
	inline comp(const dbl & _x = 0, const dbl & _y = 0) : x(_x), y(_y) {}

	inline __attribute__((always_inline)) comp operator+(const comp & b) const {
		return comp(x + b.x, y + b.y);
	}

	inline __attribute__((always_inline)) comp operator-(const comp & b) const {
		return comp(x - b.x, y - b.y);
	}

	inline __attribute__((always_inline)) comp operator*(const comp & b) const {
		return comp(x*b.x - y*b.y, x*b.y + y*b.x);
	}
};

inline __attribute__((always_inline)) void dft(comp * __restrict a, int n, bool rev = 0) {
	for(int i = 0, j = 0; i < n; ++i) {
		if(i < j) swap(a[i], a[j]);
		for(int k = n>>1; (j^=k) < k; k >>= 1) {}
	}
	for(int i = 2; i <= n; i <<= 1) {
		int len = i>>1;
		dbl ang = 2*pi/i;
		comp w = {cos(ang), sin(ang)};
		for(int j = 0; j < n; j += i) {
			comp cur(1, 0);
			for(int k = j; k < j+len; ++k) {
				comp u = a[k], v = a[k+len] * cur;
				a[k] = u + v, a[k+len] = u - v;
				cur = cur * w;
			}
		}
	}
	if(rev) {
		reverse(a+1, a+n);
		for(register int i = 0; i < n; ++i) a[i].x /= n;
	}
}

constexpr size_t FOURIER_CACHE_SIZE = 1'500'010;
static comp ta[FOURIER_CACHE_SIZE], tb[FOURIER_CACHE_SIZE];

constexpr int B = 1000;
constexpr int powB[3] = {1, 10, 100};

class uintm_t {
	vector<int> data;

	inline __attribute__((always_inline)) void clean(int carry = 0) {
		while(carry) {
			this->data.push_back(carry % B);
			carry /= B;
		}
		while(this->size() > 1 && this->data.back() == 0) this->data.pop_back();
	}

	inline __attribute__((always_inline)) void clean(long long carry) {
		while(carry) {
			this->data.push_back(carry % B);
			carry /= B;
		}
		while(this->size() > 1 && this->data.back() == 0) this->data.pop_back();
	}

public:
	// constructors
	inline __attribute__((always_inline)) uintm_t(const uintm_t & X) : data(X.data) {}

	inline __attribute__((always_inline)) uintm_t(size_t n, int value = 0) {
		data.reserve(n+2);
		data.resize(n, 0);
		data[0] = value;
	}

	inline __attribute__((always_inline)) uintm_t(const char * __restrict s, size_t sz) {
		// s: string of decimal digits
		if(sz == 0) {
			uintm_t(1, 0);
			return;
		}
		data.resize((sz-1) / 3 + 1, 0);
		for(register size_t i = (sz-1)-(sz-1)%3; i < sz; ++i) data[(sz-1)/3] += (s[sz-1-i]-'0') * powB[i%3];
		for(register size_t i = 0; i < (sz-1)/3; ++i)
			data[i] = (s[sz-1-3*i]-'0') * powB[0] + (s[sz-2-3*i]-'0') * powB[1] + (s[sz-3-3*i]-'0') * powB[2];
	}

	inline __attribute__((always_inline)) uintm_t(const int * __restrict v, size_t sz) {
		// v: array of decimal digits
		data.resize((sz-1) / 3 + 1, 0);
		if(sz == 0) {
			uintm_t(1, 0);
			return;
		}
		for(register size_t i = (sz-1)-(sz-1)%3; i < sz; ++i) data[(sz-1)/3] += v[sz-1-i] * powB[i%3];
		for(register size_t i = 0; i < (sz-1)/3; ++i)
			data[i] = v[sz-1-3*i] * powB[0] + v[sz-2-3*i] * powB[1] + v[sz-3-3*i] * powB[2];
	}

	inline __attribute__((always_inline)) uintm_t(const vector<int> & V) {
		// V: array of decimal digits
		size_t sz = V.size();
		if(sz == 0) {
			uintm_t(1, 0);
			return;
		}		
		data.resize((sz-1) / 3 + 1, 0);
		for(register size_t i = (sz-1)-(sz-1)%3; i < sz; ++i) data[(sz-1)/3] += V[sz-1-i] * powB[i%3];
		for(register size_t i = 0; i < (sz-1)/3; ++i)
			data[i] = V[sz-1-3*i] * powB[0] + V[sz-2-3*i] * powB[1] + V[sz-3-3*i] * powB[2];
	}

	// functions

	inline __attribute__((always_inline)) size_t size() const {
		return data.size();
	}

	inline __attribute__((always_inline)) void resize(size_t sz, int val = 0) {
		data.resize(sz, val);
	}

	// arithmetic operators

	inline __attribute__((always_inline)) uintm_t operator+(int x) const {
		return *this + uintm_t(1, x);
	}

	inline __attribute__((always_inline)) uintm_t operator+(const uintm_t & X) const {
		uintm_t ans(*this);
		ans.resize(max(this->size(), X.size()), 0);
		int carry = 0;
		for(register size_t i = 0; i < X.size(); ++i) {
			ans.data[i] = ans.data[i] + X.data[i] + carry;
			carry = ans.data[i] / B;
			ans.data[i] = ans.data[i] - carry * B;
		}
		ans.clean(carry);
		return ans;
	}

	inline __attribute__((always_inline)) uintm_t & operator+=(int x) {
		return (*this += uintm_t(1, x));
	}

	inline __attribute__((always_inline)) uintm_t & operator+=(const uintm_t & X) {
		this->resize(max(this->size(), X.size()), 0);
		int carry = 0;
		for(register size_t i = 0; i < X.size(); ++i) {
			this->data[i] = this->data[i] + X.data[i] + carry;
			carry = this->data[i] / B;
			this->data[i] = this->data[i] - carry * B;
		}
		this->clean(carry);
		return *this;
	}

	inline __attribute__((always_inline)) uintm_t operator-(int x) const {
		return *this - uintm_t(1, x);
	}

	inline __attribute__((always_inline)) uintm_t operator-(const uintm_t & X) const {
		// undefined for X > this
		uintm_t ans(*this);
		ans.resize(max(this->size(), X.size()), 0);
		int carry = 0;
		for(register size_t i = 0; i < X.size(); ++i) {
			ans.data[i] = ans.data[i] - X.data[i] + carry;
			carry = (ans.data[i] >= 0) ? (ans.data[i] / B) : (ans.data[i] / B - 1);
			ans.data[i] = ans.data[i] - carry * B;
		}
		ans.clean(carry);
		return ans;
	}

	inline __attribute__((always_inline)) uintm_t & operator-=(int x) {
		return (*this -= uintm_t(1, x));
	}

	inline __attribute__((always_inline)) uintm_t & operator-=(const uintm_t & X) {
		// undefined for X > this
		this->resize(max(this->size(), X.size()), 0);
		int carry = 0;
		for(register size_t i = 0; i < X.size(); ++i) {
			this->data[i] = this->data[i] - X.data[i] + carry;
			carry = (this->data[i] >= 0) ? (this->data[i] / B) : (this->data[i] / B - 1);
			this->data[i] = this->data[i] - carry * B;
		}
		this->clean(carry);
		return *this;
	}

	inline __attribute__((always_inline)) uintm_t operator*(int x) const {
		uintm_t ans(*this);
		int carry = 0;
		for(register size_t i = 0; i < ans.size(); ++i) {
			ans.data[i] = ans.data[i] * x + carry;
			carry = ans.data[i] / B;
			ans.data[i] -= carry * B;
		}
		ans.clean(carry);
		return ans;
	}

	inline __attribute__((always_inline)) uintm_t operator*(const uintm_t & X) const {
		size_t sz = this->size() + X.size() - 1, n;
		for(n = 2; n < sz; n <<= 1) {}
		assert(n < FOURIER_CACHE_SIZE);
		for(register size_t i = 0; i < n; ++i) {
			ta[i] = {static_cast<dbl>((i < this->size()) ? this->data[i] : 0), 0};
			tb[i] = {static_cast<dbl>((i < X.size()) ? X.data[i] : 0), 0};
		}
		dft(ta, n);
		dft(tb, n);
		for(register size_t i = 0; i < n; ++i) ta[i] = ta[i] * tb[i];
		dft(ta, n, 1);
		uintm_t ans(sz);
		long long carry = 0;
		for(register size_t i = 0; i < sz; ++i) {
			carry += static_cast<long long>(ta[i].x + 0.5);
			ans.data[i] = carry % B;
			carry /= B;
		}
		ans.clean(carry);
		return ans;
	}

	inline __attribute__((always_inline)) uintm_t & operator*=(int x) {
		int carry = 0;
		for(register size_t i = 0; i < this->size(); ++i) {
			this->data[i] = this->data[i] * x + carry;
			carry = this->data[i] / B;
			this->data[i] -= carry * B;
		}
		this->clean(carry);
		return *this;
	}

	inline __attribute__((always_inline)) uintm_t & operator*=(const uintm_t & X) {
		size_t sz = this->size() + X.size() - 1, n;
		for(n = 2; n < sz; n <<= 1) {}
		assert(n < FOURIER_CACHE_SIZE);
		for(register size_t i = 0; i < n; ++i) {
			ta[i] = {static_cast<dbl>((i < this->size()) ? this->data[i] : 0), 0};
			tb[i] = {static_cast<dbl>((i < X.size()) ? X.data[i] : 0), 0};
		}
		dft(ta, n);
		dft(tb, n);
		for(register size_t i = 0; i < n; ++i) ta[i] = ta[i] * tb[i];
		dft(ta, n, 1);
		this->resize(sz);
		long long carry = 0;
		for(register size_t i = 0; i < sz; ++i) {
			carry += static_cast<long long>(ta[i].x + 0.5);
			this->data[i] = carry % B;
			carry /= B;
		}
		this->clean(carry);
		return *this;
	}

	inline __attribute__((always_inline)) uintm_t operator/(int x) const {
		uintm_t ans(*this);
		int carry = 0;
		for(register int i = ans.size()-1; i >= 0; --i) {
			int t = (carry * B + ans.data[i]) / x;
			carry = carry * B + ans.data[i] - t * x;
			ans.data[i] = t;
		}
		ans.clean();
		return ans;
	}

	inline __attribute__((always_inline)) uintm_t & operator/=(int x) {
		int carry = 0;
		for(register int i = this->size()-1; i >= 0; --i) {
			int t = (carry * B + this->data[i]) / x;
			carry = carry * B + this->data[i] - t * x;
			this->data[i] = t;
		}
		this->clean();
		return *this;
	}

	// comparison operators

	inline __attribute__((always_inline)) bool operator>=(const uintm_t & X) const {
		if(this->size() != X.size()) return (this->size() > X.size());
		for(register int i = this->size()-1; i >= 0; --i) {
			if(this->data[i] == X.data[i]) continue;
			return (this->data[i] > X.data[i]);
		}
		return true;
	}

	inline __attribute__((always_inline)) bool operator>(const uintm_t & X) const {
		if(this->size() != X.size()) return (this->size() > X.size());
		for(register int i = this->size()-1; i >= 0; --i) {
			if(this->data[i] == X.data[i]) continue;
			return (this->data[i] > X.data[i]);
		}
		return false;
	}

	inline __attribute__((always_inline)) bool operator<=(const uintm_t & X) const {
		if(this->size() != X.size()) return (this->size() < X.size());
		for(register int i = this->size()-1; i >= 0; --i) {
			if(this->data[i] == X.data[i]) continue;
			return (this->data[i] < X.data[i]);
		}
		return true;
	}

	inline __attribute__((always_inline)) bool operator<(const uintm_t & X) const {
		if(this->size() != X.size()) return (this->size() < X.size());
		for(register int i = this->size()-1; i >= 0; --i) {
			if(this->data[i] == X.data[i]) continue;
			return (this->data[i] < X.data[i]);
		}
		return false;
	}

	inline __attribute__((always_inline)) bool operator==(const uintm_t & X) const {
		return this->data == X.data;
	}

	inline __attribute__((always_inline)) bool operator!=(const uintm_t & X) const {
		return this->data != X.data;
	}
};

inline __attribute__((always_inline)) uintm_t pow(int base, int n) {
	if(n <= 0) return uintm_t(1, 1);
	int e = 0;
	while((2<<e) <= n) e++;
	uintm_t res(1, base);
	for(int k = e-1; k >= 0; k--) {
		res = res * res;
		if((n>>k)&1) res = res * base;
	}
	return res;
}

inline __attribute__((always_inline)) uintm_t pow(uintm_t base, int n) {
	if(n <= 0) return uintm_t(1, 1);
	int e = 0;
	while((2<<e) <= n) e++;
	uintm_t res(base);
	for(int k = e-1; k >= 0; k--) {
		res = res * res;
		if((n>>k)&1) res = res * base;
	}
	return res;
}

}  // namespace uintm_t

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	const int MX = 1'500'010;
	char N[MX];
	scanf("%s", N);
	cat Nappr = 0, Nappr_exp = 0;
	int D = 0;
	while(N[D]) {
		if(D < 16) Nappr = Nappr * 10 + N[D] - '0';
		else Nappr_exp++;
		D++;
	}
	if(Nappr_exp == 0) {
		int ans = 100000;
		for(int k = 0; k <= 2; k++) {
			cat a = 1<<k;
			int cur = 2*k;
			while(a < Nappr) a *= 3, cur += 3;
			ans = min(ans, max(1, cur));
		}
		cout << ans << "\n";
		return 0;
	}
	dbl Nlog = log(Nappr) + Nappr_exp * log(10);
	int ans = OVER9000;
	int k_uncertain = -1, p_uncertain = -1;
	for(int k = 0; k <= 2; k++) {
		dbl diflog = (Nlog - k * log(2)) / log(3);
		dbl q = min(ceil(diflog) - diflog, diflog - floor(diflog));
		if(q < soclose) {
			k_uncertain = k;
			p_uncertain = round(diflog);
			ans = min(ans, 2 * k + 3 * p_uncertain + 3);
			continue;
		}
		int x = ceil(diflog);
		ans = min(ans, 2 * k + 3 * x);
	}
	if(k_uncertain == -1) {
		cout << ans << "\n";
		return 0;
	}
	for(int i = 0; i < k_uncertain; i++) {
		if((N[D-1]-'0')%2 != 0) N[D-1]++;
		for(int j = D-1; j >= 0; j--) {
			if((N[j]-'0')%2 != 0) N[j+1] += 5;
			N[j] = '0' + (N[j]-'0') / 2;
		}
		for(int j = D-1; j >= 0; j--) {
			int c = (N[j] - '0') / 10;
			N[j] = (N[j] - '0') % 10 + '0';
			N[j-1] += c;
		}
		while(N[0] == 0) {
			for(int j = 0; j < D-1; j++) N[j] = N[j+1];
			D--;
		}
	}
	// N <= 3^p_uncertain ?
	using uintm_t = bigint::uintm_t;
	uintm_t NB(N, D);
	uintm_t PW = bigint::pow(3, p_uncertain);
	if(PW >= NB) ans = min(ans, k_uncertain * 2 + p_uncertain * 3);
	cout << ans << "\n";
	return 0;}

// look at my code
// my code is amazing