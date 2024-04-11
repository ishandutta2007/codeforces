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

// got from neal's submission...
// How to deal with situation when len is quite small:
// just iterate sort subsequence, and find that if 
// sorted string exists in the group.

ll valid(string &s1, string &s2) {
    ll n = s1.size();
    ll l = 0, r = n;
    while (l<r && s1[l] == s2[l]) l++;
    while (l<r && s1[r-1] == s2[r-1]) r--;

    int can = is_sorted(s1.begin()+l, s1.begin()+r) || is_sorted(s2.begin()+l, s2.begin()+r);
    return 2-can;
}

ll calc(vector<string> &vec) {
    ll n = vec.size(), len = vec[0].size();
    ll ans = 0;
    if (n <= 100*len) {
        REP(i, n-1) FOR(j, i+1, n-1) {
            ans += valid(vec[i], vec[j]);
        } return ans;
    } else {
        sort(all(vec));

        ans = 2 * n*(n-1)/2;
        for (string &s : vec) {
            REP(l, len-1) FOR(r, l+2, len) {
                string temp = s;
                sort(temp.begin()+l, temp.begin()+r);
                if (temp[l] != s[l] && temp[r-1] != s[r-1]) {
                    ans -= binary_search(all(vec), temp);
                }
            }
        } return ans;
    }
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    const ll FAIL = 1337; 

    int T = 1;
    // cin >> T;
    REP(I, T) {
        ll n; cin >> n;
        map<string, vector<string>> ma;
        REP(i, n) {
            string s; cin >> s;
            string key = s; sort(all(key));
            ma[key].eb(s);
        } 

        ll ans = FAIL * n*(n-1)/2;
        for (auto& [_, vec] : ma) {
            ll sz = vec.size();
            ans -= FAIL * sz*(sz-1)/2;
            ans += calc(vec);
        } 

        cout << ans << endl;
    }
    return 0;
}