#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef tuple<ll, ll, ll> t3l;
typedef tuple<ll, ll, ll, ll> t4l;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define ef emplace_front
#define em emplace
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define _1 first
#define _2 second

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))
#define ln cout << endl;

#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#define err(...)
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

vi diam;
void manacher(string str) {
	vector<char> s;
	REP(i, str.size()) {
		s.eb(str[i]);
		if (i != str.size() - 1) s.eb('#');
	}

	ll n = s.size(); diam = vi(n, 0);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 1 : min(diam[l + r - i], r - i);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
			k++;
		}
		diam[i] = k--;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}
}


int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
		string s; cin >> s;
		ll n = s.size();
		// manacher(s); dbg(diam);

		vl lim(n+2, -1), cnt(26, 0);
		ll l = 0, r = 0, tot = 0;
		while (r<n) {
			while (r<n && tot<3) {
				ll val = s[r++]-'a';
				if (!cnt[val]) tot++;
				cnt[val]++;
			}
			while (l<r && tot>=3) {
				lim[l] = r;
				ll val = s[l++]-'a';
				cnt[val]--;
				if (!cnt[val]) tot--;
			}
		}
		dbg(lim);


		ll q; cin >> q;
		REP(i, q) {
			ll l, r; cin >> l >> r;
			bool can = false;
			ll mid = l+r-2;

			if (s[l-1] != s[r-1]) can = true;
			if (r >= lim[l-1] && lim[l-1] != -1) can = true;
		
			if (l == r) can = true;
			if (can) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
    return 0;
}