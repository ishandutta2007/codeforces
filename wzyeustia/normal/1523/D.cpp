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

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());


// Very good question for bitmask dp and randomization.

// Randomization: need a mask agreed by at least half.
// Randomly select an instance, the probability that 
// it agrees with answer mask >= 1/2.
// Therefore, pick an instance 50 times, enough confidence that
// at least one of them will agree with answer mask.

// Bitmask dp: need to count #instance that agrees with every submask.
// First, cnt[mask] = #instance with this mask.
// Then transfer mask's contribution to its submask.
// We do it bit by bit, such that we won't overcount.
// If mask's bit is set, we transfer it to its unset pair, 
// which is cnt[mask ^ bit] += cnt[mask].
// Finally, cnt[mask] will be what we want.
int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, m, p; cin >> n >> m >> p;
        vl a(n); REP(i, n) {
            string s; cin >> s;
            REP(j, m) if (s[j] == '1') {
                a[i] |= (1ll << (m-1-j)); 
            }
        }
        dbg(a);

        vl randNum(n);
        iota(all(randNum), 0);
        shuffle(all(randNum), rng);
        dbg(randNum);

        ll ans = 0, ansCnt = 0;
        REP(iterCnt, min(n, 50ll)) {
            ll base = a[randNum[iterCnt]];

            vl pos;
            REP(tt, m) {
                ll bit = (1ll << tt);
                if (base & bit) pos.eb(tt);
            }

            ll sz = pos.size();
            vl cnt((1ll << sz), 0), bits((1ll << sz), 0);
            REP(i, n) {
                ll tot = 0;
                REP(j, sz) {
                    ll bit = (1ll << pos[j]);
                    if (a[i] & bit) tot |= (1ll << j);
                }
                cnt[tot]++;
            }

            REP(tt, sz) {
                ll bit = (1ll << tt);
                REP(i, (1ll << sz)) if (i & bit) {
                    bits[i]++;
                    cnt[i^bit] += cnt[i];
                }
            }
            // dbg(cnt); dbg(bits);

            bool edit = false;
            ll msk = 0;
            REP(i, (1ll << sz)) if (cnt[i]*2 >= n && bits[i] > ansCnt) {
                edit = true;
                msk = i, ansCnt = bits[i];
            }

            if (edit) {
                ll newMask = 0;
                REP(tt, sz) {
                    if (msk & (1ll << tt)) newMask |= (1ll << pos[tt]);
                }
                ans = newMask;
            }
        }

        dbg(ans, ansCnt);
        string outStr(m, '0');
        ROF(i, m-1, 0) {
            if (ans & (1ll << i)) outStr[m-1-i] = '1';
        } 
        cout << outStr << endl;
    }
    return 0;
}