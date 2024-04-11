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
const ll SIZE = 2e6+3; 

const ll MOD = 1e9+7;
ll myMod(ll n) {return (n % MOD + MOD) % MOD;}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    vl rev(12, 9999);
    rev[0] = 0, rev[1] = 1, rev[2] = 5, rev[5] = 2, rev[8] = 8;

    int T = 1;
    cin >> T;
    REP(I, T) {
        ll maxH, maxM; cin >> maxH >> maxM;
        string time; cin >> time;
        ll leftH = (time[0]-'0')*10 + (time[1]-'0');
        ll leftM = (time[3]-'0')*10 + (time[4]-'0');
        
        while (true) {
            ll rightM = rev[leftH%10]*10 + rev[leftH/10];
            ll rightH = rev[leftM%10]*10 + rev[leftM/10];

            if (rightM < maxM && rightH < maxH) {
                // cout << "ans : ";
                if (leftH < 10) cout << "0";
                cout << leftH << ":";
                if (leftM < 10) cout << "0";
                cout << leftM << endl;
                break;
            }

            leftM++;
            if (leftM >= maxM) {
                leftM-=maxM;
                leftH++;
            }
            if (leftH >= maxH) {
                leftH -= maxH;
            }
        }

    }
    return 0;
}