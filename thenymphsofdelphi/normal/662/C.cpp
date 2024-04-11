#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = l; i < r; i++)
#define ForE(i, l, r) for (auto i = l; i <= r; i++)
#define FordE(i, l, r) for (auto i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pair <int, int>>;
using vvi = vector <vector <int>>;

// O(n log n)
template<class T, char Conv = '^'>
void fast_walsh_hadamard_transform(vector<T> &a, bool invert = false){
    int n = (int)a.size();
    for(auto len = 1; len < n; len <<= 1){
        for(auto i = 0; i < n; i += len << 1){
            for(auto j = 0; j < len; ++ j){
                T u = a[i + j], v = a[i + j + len];
                if(Conv == '^') a[i + j] = u + v, a[i + j + len] = u - v;
                if(Conv == '|') a[i + j + len] += invert ? -u : u;
                if(Conv == '&') a[i + j] += invert ? -v : v;
            }
        }
    }
    if(Conv == '^' && invert){
        auto inv_n = T(1) / n;
        for(auto &x: a) x *= inv_n;
    }
}

// O(n log n)
template<class T, char Conv = '^'>
vector<T> convolute_fwht(vector<T> p, vector<T> q){
    int n = (int)p.size();
    assert(p.size() == q.size() && __builtin_popcount(n) == 1);
    fast_walsh_hadamard_transform<T, Conv>(p), fast_walsh_hadamard_transform<T, Conv>(q);
    for(auto i = 0; i < n; ++ i) p[i] *= q[i];
    fast_walsh_hadamard_transform<T, Conv>(p, true);
    return p;
}

const int N = 1 << 20;

int n, m;
string s[20];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    For(i, 0, n){
        cin >> s[i];
    }

    vector <double> cnt(1 << n);
    For(j, 0, m){
        int x = 0;
        For(i, 0, n){
            x = (x << 1) | (s[i][j] - '0');
        }
        cnt[x]++;
    }
    vector <double> f(1 << n);
    For(i, 0, (1 << n)){
        f[i] = min(__builtin_popcount(i), __builtin_popcount(((1 << n) - 1) ^ i));
    }

    vector <double> cac = convolute_fwht(cnt, f);
    cout << fixed << setprecision(0) << round(*min_element(bend(cac))) << endl;
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/