#pragma GCC optimize ("-O3")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define rsz resize
#define mp make_pair
#define bk back()

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())

using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using ul = unsigned long long;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? a = b, true : false; }

const int INF = 1e9;
mt19937 rng(1337228);

const int N = 1e5+7, SZ = 1e7;

int d_cnt(int n) {
    int res = 0;
    for(int i = 1; i*i <= n; ++i)
        if(n%i == 0) res += i*i < n ? 2 : 1;
    return res;
}

bool is_prime(int n) {
    for(int i = 2; i*i <= n; ++i)
        if(n%i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin >> n >> m; k = sqrt((double)n);
    
    vi d(n+1, 1), md(n+1);
    for(int i = 2; i <= n; ++i) {
        if(!md[i]) {
            md[i] = i;
            if(i <= k)
                for(int j = i*i; j <= n; j += i)
                    md[j] = i;
        }
        int lg = 0, t = i;
        for(int j = i; j > 1; j /= md[j])
            if(md[j] == md[i]) ++lg, t /= md[i];
        d[i] = d[t] * (lg + 1);
    }
    
    int e = 0, i = 1;
    vi banned(n+1, 0);
    
    while(i < n && e < m) e += d[++i] - 1;
    if(e < m) { cout << "No" << endl; exit(0); }
    
#define B(x) banned[x] = 1, e -= d[x] - 1
    
    if(m == 6) B(4);
    if(m == 15) B(9);
    if(m == 19 || m == 20) B(8);
    if(m == 31) B(9);
    if(m == 36) B(10);
    if(m == 54 || m == 55) B(14);
    if(m == 69) B(16);
    if(m == 75 || m == 76) B(21), B(25);
    if(m >= 97 && m <= 99) B(21), B(25);
    if(m == 112 || m == 113) B(21), B(25);
    if(m == 120 || m == 142 || m == 143) B(33), B(35);
    if(m >= 191 && m <= 193) B(33), B(35), B(55);
    if(m == 244 || m == 353) B(55);
    if(m == 468) B(77);
    
    for(int j = i/2+1; j <= i && e > m; ++j)
        if(md[j] == j) --e, banned[j] = 1;
    cout << "Yes" << endl;
    vi res;
    for(int j = 1; j <= i; ++j)
        if(!banned[j]) res.pb(j);
    cout << res.size() << endl;
    for(int i : res) cout << i << ' ';
}