#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tll;
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

// FILL by byte!!!
#define FILL(arr, num) memset(arr, num, sizeof(arr))

#define ln printf("\n");

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
#define err(...)
#endif
// end

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename T>
using MaxHeap = priority_queue<T>;

const ld PI = 3.14159265358979323846;
const ld E = 2.718281828459;
const ll MOD = 1e9+7;
ll M(ll n) {return (n % MOD + MOD) % MOD;}
ll pow2(ll n) {return 1ll << n;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    REP(I, T) {
        string str; cin >> str;
        ll n = str.size();
        map<char, set<char>> adj;
        FOR(i, 1, n-1) {
            adj[str[i]].em(str[i-1]);
            adj[str[i-1]].em(str[i]);
        }

        bool can = true;
        FOR(ch, 'a', 'z')
            if (adj[ch].size() >= 3) can = false;

        vl used(256);
        vector<char> ans;
        FOR(ch, 'a', 'z') {
            if (used[ch] || adj[ch].size() > 1) continue;
            used[ch] = 1; ans.eb(char(ch));

            if (adj[ch].size() == 1){
                char last = ch, nxt = *adj[ch].begin();
                if (used[nxt]) can = false;
                used[nxt] = 1, ans.eb(nxt);

                while (adj[nxt].size() != 1) {
                    if (*adj[nxt].begin() != last) 
                        last = nxt, nxt = *adj[nxt].begin();
                    else 
                        last = nxt, nxt = *(++adj[nxt].begin());
                    dbg(last, nxt);
                    if (used[nxt]) {can = false; break;}
                    used[nxt] = 1, ans.eb(nxt);
                }
            }
        }

        if (can && ans.size() == 26) {
            cout << "YES" << endl;
            for (auto ch : ans) {
                cout << ch;
            }cout << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}