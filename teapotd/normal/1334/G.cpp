#pragma GCC optimize("O3")
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(18);
	run();
	return 0;
}

template<class T> Vi kmp(const T& str) {
	Vi ps; ps.pb(-1);
	each(x, str) {
		int k = ps.back();
		while (k >= 0 && str[k] != x) k = ps[k];
		ps.pb(k+1);
	}
	return ps;
}

template<class T>
Vi match(const T& str, T pat) {
	int n = sz(pat);
	pat.pb('#');
	pat.insert(pat.end(), all(str));
	Vi ret, ps = kmp(pat);
	rep(i, 0, sz(ps)) {
		if (ps[i] == n) ret.pb(i-2*n-1);
	}
	return ret;
}

ll modPow(ll a, ll e, ll m) {
	ll t = 1 % m;
	while (e) {
		if (e % 2) t = t*a % m;
		e /= 2; a = a*a % m;
	}
	return t;
}

template<ll M, ll R, bool dit>
void ntt(vector<ll>& a) {
	static vector<ll> w(2, 1);
	int n = sz(a);

	for (int k = sz(w); k < n; k *= 2) {
		w.resize(n, 1);
		ll c = modPow(R, M/2/k, M);
		if (dit) c = modPow(c, M-2, M);
		rep(i, k+1, k*2) w[i] = w[i-1]*c % M;
	}

	for (int t = 1; t < n; t *= 2) {
		int k = (dit ? t : n/t/2);
		for (int i=0; i < n; i += k*2) rep(j,0,k) {
			ll &c = a[i+j], &d = a[i+j+k];
			ll e = w[j+k], f = d;
			d = (dit ? c - (f=f*e%M) : (c-f)*e % M);
			if (d < 0) d += M;
			if ((c += f) >= M) c -= M;
		}
	}
}

template<ll M = (119<<23)+1, ll R = 62>
void convolve(vector<ll>& a, vector<ll> b) {
	int len = max(sz(a) + sz(b) - 1, 0);
	int n = 1 << (32 - __builtin_clz(len));
	ll t = modPow(n, M-2, M);
	a.resize(n); b.resize(n);
	ntt<M,R,0>(a); ntt<M,R,0>(b);
	rep(i, 0, n) a[i] = a[i]*b[i] % M * t % M;
	ntt<M,R,1>(a);
	a.resize(len);
}

string getStable(string s, const Vi& perm) {
	each(c, s) {
		if (perm[c-'a'] != c-'a') {
			c = '?';
		}
	}
	return s;
}

Vi perm;
string s, t;

void run() {
	perm.resize(26);
	each(k, perm) {
		cin >> k;
		k--;
	}

	cin >> s >> t;

	string s2 = getStable(s, perm), t2 = getStable(t, perm);
	vector<bool> good(sz(t)-sz(s)+1);

	each(i, match(t2, s2)) {
		good[i] = 1;
	}

	vector<ll> pat, target;

	rep(j, 0, 26) if (perm[j] != j) {
		pat.resize(sz(s));
		target.resize(sz(t));
		char c1 = char(j+'a'), c2 = char(perm[j]+'a');
		int wanted = 0;

		rep(i, 0, sz(s)) {
			pat[sz(s)-i-1] = (s[i] == c1);
			wanted += int(pat[sz(s)-i-1]);
		}

		rep(i, 0, sz(t)) {
			target[i] = (t[i] == c1 || t[i] == c2);
		}

		convolve(target, pat);

		rep(i, 0, sz(t)-sz(s)+1) {
			if (target[i+sz(s)-1] != wanted) {
				good[i] = 0;
			}
		}
	}

	for (bool b : good) cout << b;
	cout << endl;
}