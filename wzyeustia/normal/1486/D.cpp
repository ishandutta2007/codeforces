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

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n, k; cin >> n >> k;
        vl arr(n); REP(i, n) cin >> arr[i];
        vl aux(arr); sort(all(aux));

        ll ansIdx = (n-1)/2;
        ll l = 0, r = n-1;
        while (l <= r) {
            dbg(l, r);
            ll mid = (l+r)/2;
            ll num = aux[mid];

            vl isGood(n), jump(n);
            REP(i, n-1) jump[i] = i+1;

            stack<ll> stk;
            REP(i, n) {
                isGood[i] = arr[i]>=num;
                if (isGood[i]) {
                    stk.emplace(i);
                } else {
                    if (!stk.empty()) {
                        jump[stk.top()] = i+1;
                        stk.pop();
                    }
                }
            }

            dbg(isGood); dbg(jump);
            
            ll cnt = 0, lhs = 0;
            bool flag = false;
            REP(i, k) cnt+=isGood[i];
            FOR(rhs, k, n-1) {
                cnt+=isGood[rhs];
                
                if (rhs-jump[lhs]+1 >= k) {
                    cnt -= (jump[lhs]-lhs)/2; 
                    lhs = jump[lhs];
                }
                if (cnt >= (rhs-lhs+1)/2 + 1) {
                    dbg(lhs, rhs, cnt);
                    flag = true; break;
                }
            }
            
            if (flag) {
                chkmax(ansIdx, mid);
                l = mid+1;
            } else {
                r = mid-1;
            }
        }

        dbg(aux[ansIdx]);
        cout << aux[ansIdx] << endl;
    }
    return 0;
}