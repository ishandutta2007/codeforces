#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define FOR(i, a, b) for (ll (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (ll (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define ln cout << endl;

// Can I use this?
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll SIZE = 3e2+3; 

const ll MOD = 998'244'353;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}

ll query(ll l, ll r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();
    ll ret; cin >> ret;
    return ret;
}

void answer(ll ans) {
    cout << "! " << ans << endl;
    cout.flush();
}

void solve(ll left, ll right, ll maxPos) {
    ll ans;
    if (maxPos == right) {
        ll l = left, r = right;
        while (l < r) {
            
            ll mid = (l+r)/2;
            dbg(l, r, mid);
            if (mid+1==right) {
                ll finalPos = query(mid, right);
                dbg(finalPos, maxPos);
                if (finalPos == maxPos) {
                    ans = mid; break;
                } else {
                    ans = l; break;
                }
            }

            ll pos = query(mid+1, right);

            if (pos == maxPos) l = mid+1;
            else r = mid;
        }

        if (l == r) ans = l;
        answer(ans);
    } else {
        ll l = left, r = right;
        while (l < r) {
            ll mid = (l+r)/2;
            if (left == mid) {
                ans = mid+1; break;
            }

            ll pos = query(left, mid);

            if (pos == maxPos) r = mid;
            else l = mid+1;
        }

        if (l == r) ans = l;
        answer(ans);
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        ll left = 1, right = n;
        ll pos = query(left, right);
        
        if (pos == 1) {solve(1, n, 1); continue;}
        if (pos == n) {solve(1, n, n); continue;}

        ll posLeft = query(1, pos);
        if (posLeft == pos) {
            solve(1, pos, pos);
        }
        else {
            solve(pos, n, pos);
        }

    }
    return 0;
}