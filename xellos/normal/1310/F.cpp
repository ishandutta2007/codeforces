#include <iostream>
#include <cassert>
#include <random>
#include <algorithm>
using namespace std;

template <typename T>
T pow(T a, T e, T mod) {
	if(!e) return 1;
	T x = pow(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

template <typename T, typename exp_t, T (*multiply)(T, T)>
T pow(T a, exp_t e) {
	if(!e) return 1;
	T x = pow<T, exp_t, multiply>(a, e/2);
	x = multiply(x, x);
	return (e&1) ? multiply(x, a) : x;
}

template <typename CRT_t>
CRT_t CRT(const CRT_t * rem, const CRT_t * p_v, const int * p_e, const int p_n) {
	// return e: e % p_v[i]**p_e[i] == rem[i] for 0 <= i < p_n
	CRT_t ret = 0, mod = 1;
	for(int i = 0; i < p_n; i++) for(int j = 0; j < p_e[i]; j++) mod *= p_v[i];
	// e == (sum rem[i] * c[i]) % prod p_v[i]**p_e[i]
	for(int i = 0; i < p_n; i++) {
		// pr[i] == prod p_v[j]**p_e[j] for j != i
		// c[i] == pr[i] * (inverse of pr[i] modulo p_v[i]**p_e[i]) == pr[i] * inv[i]
		CRT_t pr = mod, pw = 1;
		for(int j = 0; j < p_e[i]; j++) pr /= p_v[i], pw *= p_v[i];
		CRT_t inv = pow(pr % pw, pw - pw / p_v[i] - 1, pw);
		CRT_t add = inv * rem[i] % pw * pr;
		if(add >= mod-ret) ret += add-mod;
		else ret += add;
	}
	return ret;
}

template <typename BSGS_t, typename exp_t, BSGS_t (*multiply)(BSGS_t, BSGS_t)>
exp_t BSGS(const BSGS_t a, const BSGS_t b, const exp_t order) {
	exp_t sqrt = 1;
	while(sqrt*sqrt < order) sqrt++;
	static pair<BSGS_t, exp_t> try_small[20000];
	static pair<BSGS_t, exp_t> try_large[20000];
	BSGS_t cur = 1;
	for(BSGS_t i = 0; i < sqrt; i++) {
		try_small[i] = {cur, i};
		cur = multiply(cur, a);
	}
	cur = b;
	BSGS_t a_pw = pow<BSGS_t, exp_t, multiply>(a, order-sqrt);
	for(exp_t i = 0; i < sqrt; i++) {
		try_large[i] = {cur, i};
		cur = multiply(cur, a_pw);
	}
	sort(try_small, try_small+sqrt);
	sort(try_large, try_large+sqrt);
	for(exp_t i = 0, j = 0; i < sqrt; i++) {
		while(j < sqrt && try_large[j].first < try_small[i].first) j++;
		if(j == sqrt) return exp_t(-1);
		if(try_large[j].first == try_small[i].first)
			return try_large[j].second * sqrt + try_small[i].second;
	}
	return exp_t(-1);
}

template <typename PH_t, typename exp_t, PH_t (*multiply)(PH_t, PH_t)>
exp_t PohligHellman_pw(const PH_t g, const PH_t a, const exp_t p_v, const int p_e) {
	// return e: g**e == a, or -1 if no such e exists
	exp_t ret = 0, pw_down = 1, pw_up = 1;
	for(int k = 0; k < p_e-1; k++) pw_up *= p_v;
	exp_t pw = pw_up * p_v;
	PH_t g_pw = pow<PH_t, exp_t, multiply>(g, pw_up);
	for(int k = 0; k < p_e; k++) {
		PH_t h = pow<PH_t, exp_t, multiply>(multiply(pow<PH_t, exp_t, multiply>(g, pw-ret), a), pw_up);
		exp_t d = BSGS<PH_t, exp_t, multiply>(g_pw, h, p_v);
		if(d == exp_t(-1)) return exp_t(-1);
		ret += pw_down * d;
		pw_down *= p_v, pw_up /= p_v;
	}
	return ret;
}

template <typename PH_t, typename exp_t, PH_t (*multiply)(PH_t, PH_t)>
exp_t PohligHellman(const PH_t g, const PH_t a, const exp_t * p_v, const int * p_e, const int p_n) {
	// return e: g**e == a, or -1 if no such e exists
	static exp_t e_rem[100];
	exp_t order = 1;
	for(int i = 0; i < p_n; i++) for(int j = 0; j < p_e[i]; j++) order *= p_v[i];
	for(int i = 0; i < p_n; i++) {
		exp_t pw = 1;
		for(int j = 0; j < p_e[i]; j++) pw *= p_v[i];
		PH_t g_pow = pow<PH_t, exp_t, multiply>(g, order/pw);
		PH_t a_pow = pow<PH_t, exp_t, multiply>(a, order/pw);
		e_rem[i] = PohligHellman_pw<PH_t, exp_t, multiply>(g_pow, a_pow, p_v[i], p_e[i]);
		if(e_rem[i] == exp_t(-1)) return exp_t(-1);
	}
	return CRT(e_rem, p_v, p_e, p_n);
}

template <typename PH_t, typename exp_t, PH_t (*multiply)(PH_t, PH_t)>
PH_t DiscreteLog(const PH_t a, const PH_t b, const exp_t order) {
	// return e: a**e == b, or -1 if no such e exists
	// factorise assuming all prime factors are small
	static exp_t p_v[100];
	static int p_e[100];
	int p_n = 0;
	exp_t o = order;
	for(exp_t i = 2; i*i <= o; i++) if(o%i == 0) {
		p_v[p_n] = i;
		p_e[p_n] = 0;
		while(o%i == 0) p_e[p_n]++, o /= i;
		p_n++;
	}
	if(o > 1) {
		p_v[p_n] = o;
		p_e[p_n] = 1;
		p_n++;
	}
	// try random generators
    mt19937_64 rng(a*b);
	PH_t g = 0;
	while(true) {
		PH_t try_g = g ? g : (rng() % order);
		if(!try_g) continue;
		exp_t e_a = PohligHellman<PH_t, exp_t, multiply>(try_g, a, p_v, p_e, p_n);
		if(e_a == exp_t(-1)) {
			try_g = 0;
			continue;
		}
		exp_t e_b = PohligHellman<PH_t, exp_t, multiply>(try_g, b, p_v, p_e, p_n);
		if(e_b == exp_t(-1)) {
			try_g = 0;
			continue;
		}
		g = try_g;
		// e_a * e == e_b + K * order
		static exp_t e_rem[100];
		for(int i = 0; i < p_n; i++) {
			exp_t pw = 1;
			for(int j = 0; j < p_e[i]; j++) pw *= p_v[i];
			exp_t e_a_rem = e_a % pw, e_b_rem = e_b % pw;
			while(pw > 1 && e_a_rem % p_v[i] == 0) {
				if(e_b_rem % p_v[i] != 0) return -1;
				pw /= p_v[i], e_a_rem /= p_v[i], e_b_rem /= p_v[i];
			}
			// e_a_rem * e == e_b_rem + K * pw
			e_rem[i] = (pw != 1) ? e_b_rem * pow(e_a_rem, pw-pw/p_v[i]-1, pw) % pw : 0;
		}
		return CRT(e_rem, p_v, p_e, p_n);
	}
}

using cat = unsigned long long;

cat multiply_nocache(cat a, cat b);

cat cache[64][64];
char cache_used[64][64];

cat multiply_pw2(int a, int b) { // < 64
	a &= 63, b &= 63;
	if(cache_used[a][b]) return cache[a][b];
	if(a == 0 || b == 0) {
		cache_used[a][b] = 1;
		cache[a][b] = (1ULL<<a) * (1ULL<<b);
		return (1ULL<<a) * (1ULL<<b);
	}
	int n = 0;
	while(n+1 < 6 && ((1<<(n+1)) <= a || (1<<(n+1)) <= b)) n++;
	int pw = 1<<n;
	if(a >= pw && b >= pw) {
		cache_used[a][b] = 1;
		cache[a][b] = multiply_nocache(3ULL<<(pw-1), multiply_pw2(a^pw, b^pw));
		return cache[a][b];
	}
	if(a >= pw) {
		cache_used[a][b] = 1;
		cache[a][b] = multiply_pw2(a^pw, b) << pw;
		return cache[a][b];
	}
	if(b >= pw) {
		cache_used[a][b] = 1;
		cache[a][b] = multiply_pw2(a, b^pw) << pw;
		return cache[a][b];
	}
	assert(false);
	return -1;
}

cat multiply_nocache(cat a, cat b) {
	cat ret = 0;
	for(int i = 0; a; i++, a /= 2) if(a&1) {
		cat b_c = b;
		for(int j = 0; b_c; j++, b_c /= 2) if(b_c&1)
			ret ^= multiply_pw2(i, j);
	}
	return ret;
}

cat __attribute__((optimize("-Ofast,-funroll-loops"))) __attribute__((target("arch=core-avx2"))) multiply(cat a, cat b) {
	cat ret = 0;
	cat x[64];
	for(int j = 0; j != 64; j++, b /= 2) x[j] = -(b&1);
	for(int i = 0; a; i++, a /= 2) if(a&1) {
		cat y[64];
		cat * __restrict cache_ptr = &(cache[i][0]);
		for(int j = 0; j != 64; j++) y[j] = x[j] & cache_ptr[j];
		for(int j = 0; j != 64; j++) ret ^= y[j];
	}
	return ret;
}

int main() {
	for(int i = 0; i < 64; i++) for(int j = 0; j < 64; j++) multiply_nocache(1ULL<<i, 1ULL<<j);
	int T;
	cin >> T;
	while(T--) {
		cat a, b;
		cin >> a >> b;
		cat ans = DiscreteLog<cat, cat, &multiply>(a, b, 0xFFFFFFFFFFFFFFFF);
		if(ans+1 == 0) cout << "-1\n";
		else cout << ans << "\n";
	}
}