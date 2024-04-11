#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)

#define MKPR make_pair
#define ALL(c) begin(c), end(c)
#define ALLn(arr, n) arr, arr+n
#define FILL0(arr) memset(arr, 0, sizeof(arr))
#define FILL1(arr) memset(arr, -1, sizeof(arr))

#define ln cout << endl;

typedef unsigned long long ULL;
typedef unsigned int Uint;
typedef unsigned char Byte;
typedef long double ld;

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


constexpr ll MOD = 1000000007;
constexpr int INF = 0x7f7f7f7f;
constexpr double EPS = 1e-8;
//Common variables

template <typename T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;

const ll SIZE = 1e6+1;

void answer(ll ans) {
    cout << "C " << ans << endl;
    fflush(stdout);
}


vector <int> prime;
bool is_composite[SIZE];
ll n;

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.push_back (i);
		for (int j = 2; i * j < n; ++j)
			is_composite[i * j] = true;
	}
}

vector<bool> exist(SIZE, 1);
bool query(ll num, bool remove = true, bool debug = false) {

    ll got = 0;
    if (!debug) {
        if (remove) cout << "B " << num << endl;
        else cout << "A " << num << endl;
        fflush(stdout);
        cin >> got;
    }
    

    ll mul = 1, cnt = 0;
    while (num * mul <= n) {
        cnt += exist[num*mul];
        if (remove) exist[num*mul] = false;
        mul++;
    }

    // dbg(got, cnt);
    return got == cnt;
}

int main(int argn, char **argv) {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    const ll MOD = 1e9+7;

    int T = 1;
    // cin >> T;
    REP(I, T) {
        cin >> n;
        sieve(SIZE);
        // dbg(prime.size());

        

        ll ans = 1, cnt = 0, idx = 0;
        bool flag = 1; 

        // clock_t z = clock();
        // for (idx = 0; prime[idx] <= n; idx++) {
        //     ll pr = prime[idx];
        //     query(pr, 1, 1);
        // }
        // cout << "Total Time: " << (double)(clock() - z) / CLOCKS_PER_SEC << endl;

        for (idx = 0; prime[idx] <= n; idx++) {
            vector<int> factors;

            ll pr = prime[idx];
            if (!query(pr)) factors.eb(pr);
            cnt++;

            if (flag && (cnt >= 100 || prime[idx+1] > n)) {
                if (!query(1, 0)) {
                    flag = false;
                    for (int k = idx-cnt+1; k <= idx; k++) {
                        if (!query(prime[k], 0)) {
                            factors.eb(prime[k]);
                            break;
                            
                            
                        }
                    }
                }
                cnt = 0;
            }

            for (auto fac : factors) {
                for (ll num = fac; num <= n; num *= fac) {
                    if (!query(num, 0)) ans *= fac;
                    else break;
                }
            }
        }

        answer(ans);
    }
    return 0;
}