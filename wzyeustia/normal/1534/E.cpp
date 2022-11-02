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
ll MOD = 1e9+7; // 998'244'353;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)

ll n, k;
ll query(vl &vec) {
    cout << "? ";
    REP(i, k) cout << vec[i] << " ";
    cout << endl; cout.flush();
    ll ret; cin >> ret;
    return ret;
}

void answer(ll ans) {
    cout << "! " << ans << endl; 
    cout.flush();
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n >> k;
        if (n&1 && !(k&1)) {
            cout << -1 << endl;
        } else {
            ll cnt = 0, tot = 0, maxWaste, need;
            while (true) {
                cnt++, tot+=k;
                maxWaste = (cnt-1)/2 * 2*n;
                need = tot-n;

                if (need >= 0 && need%2==0 && need <= maxWaste) break;
            }
            dbg(cnt, tot);
            dbg(need, maxWaste);

            vvl num(cnt, vl(k));
            
            vl done(n+2, 0);
            ll most = (cnt-1)/2 * 2 + 1, crt = 1;
            REP(j, k) REP(i, cnt) {
                num[i][j] = crt;
                if (done[crt]) need--;
                done[crt]++;
                if (done[crt] == most || !need) crt++;
            } 

            ll ans = 0;
            REP(i, cnt) ans ^= query(num[i]);
            answer(ans);
        }
    }
    return 0;
}