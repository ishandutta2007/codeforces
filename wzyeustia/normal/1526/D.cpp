#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> t3l;
typedef tuple<ll, ll, ll, ll> t4l;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
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
ll MOD = 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

// BIT
int lowbit(int num) {return num & (-num);}

void init(vl &arr, int n, vl &BIT) {
    FOR(i, 1, n) {
        BIT[i] = arr[i] - arr[i-lowbit(i)];
    }
}

int query(int k, vl &BIT) {
    int sum = 0;
    for (int i = k; i > 0; i-=lowbit(i)) {
        sum += BIT[i];
    }
    return sum;
}

void update(int l, int r, int delta, vl &BIT) {
    for (int i = l; i < BIT.size(); i+=lowbit(i)) {
        BIT[i] += delta;
    }
    for (int i = r+1; i < BIT.size(); i+=lowbit(i)) {
        BIT[i] -= delta;
    }
}

map<ll, ll> idx, chr;

ll solve(string s, string t) {
	ll n = s.size();
	vvl pos(4);
	vl ptr(4, 0);
	REP(i, n) {
		ll index = idx[s[i]];
		pos[index].eb(i+1);
	}

	vl BIT(n+2, 0);

	ll ret = 0;
	REP(i, n) {
		ll crt = idx[t[i]], ori = pos[crt][ptr[crt]++];
		ret += max(0ll, ori - (i+1) + query(i+1, BIT));
		update(1, crt, 1, BIT);
	}

	return ret;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

	idx['A'] = 0, idx['N'] = 1, idx['O'] = 2, idx['T'] = 3;
	chr[0] = 'A', chr[1] = 'N', chr[2] = 'O', chr[3] = 'T';	

    int T = 1;
    cin >> T;
    REP(I, T) {
        string s; cin >> s;
		ll n = s.size();

		vl cnt(5, 0); vector<ld> tot(5, 0);
		REP(i, n) {
			cnt[idx[s[i]]]++;
			tot[idx[s[i]]] += i;
		}

		vvl pos(4);
		REP(i, n) {
			ll index = idx[s[i]];
			pos[index].eb(i+1);
		}

		REP(i, 4) dbg(pos[i]);

		ll mx = -1;
		vector<char> ans;

		vl perm(4); REP(i, 4) perm[i] = i;
		do {
			// dbg(perm);
			ll p = 0;
			vector<char> t(n);
			REP(i, 4) {
				REP(j, cnt[perm[i]]) t[p++] = chr[perm[i]];
			}
			// dbg(t);

			vl BIT(n+2, 0), ptr(4, 0);
			ll ret = 0;
			REP(i, n) {
				ll crt = idx[t[i]], ori = pos[crt][ptr[crt]++];
				ret += max(0ll, ori - (i+1) + query(ori, BIT));
				update(1, ori, 1, BIT);
			}

			if (ret > mx) {
				mx = ret;
				ans = t;
			}
			
		} while (next_permutation(all(perm))); 

		dbg(ans); dbg(mx);
		for (auto c: ans) {
			cout << c;
		}cout << endl;
    }
    return 0;
}