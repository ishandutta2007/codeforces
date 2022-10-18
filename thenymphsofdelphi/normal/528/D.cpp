#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 1e5 + 5, M = 3e5 + 5;

void fast_fourier_transform(vector<complex<double>> &a, const bool invert = false){ // O(n log n)
    int n = (int)a.size();
    for(auto i = 1, j = 0; i < n; ++ i){
        int bit = n >> 1;
        for(; j & bit; bit >>= 1) j ^= bit;
        j ^= bit;
        if(i < j) swap(a[i], a[j]);
    }
    for(auto len = 1; len < n; len <<= 1){
        double theta = acos(-1) / len * (invert ? -1 : 1);
        complex<double> w(cos(theta), sin(theta));
        for(auto i = 0; i < n; i += len << 1){
            complex<double> wj(1);
            for(auto j = 0; j < len; ++ j, wj *= w){
                complex<double> u = a[i + j], v = wj * a[i + j + len];
                a[i + j] = u + v, a[i + j + len] = u - v;
            }
        }
    }
    if(invert){
        double inv_n = 1.0 / n;
        for(auto &x: a) x *= inv_n;
    }
}
template<class T>
vector<T> convolute(const vector<T> &p, const vector<T> &q){
    if(min(p.size(), q.size()) < 250){
        vector<T> res((int)p.size() + (int)q.size() - 1);
        for(auto i = 0; i < p.size(); ++ i) for(auto j = 0; j < q.size(); ++ j) res[i + j] += p[i] * q[j];
        return res;
    }
    vector<complex<double>> f(p.begin(), p.end()), g(q.begin(), q.end());
    int m = max(int(p.size()) + int(q.size()) - 1, 1), n = m;
    if(__builtin_popcount(n) != 1) n = 1 << __lg(n) + 1;
    f.resize(n), g.resize(n);
    fast_fourier_transform(f), fast_fourier_transform(g);
    for(auto i = 0; i < n; ++ i) f[i] *= g[i];
    fast_fourier_transform(f, true);
    vector<T> res(m);
    for(auto i = 0; i < m; ++ i) res[i] = round(f[i].real());
    return res;
}

int n, m, k;
string s, t;

char c[4] = {'A', 'T', 'G', 'C'};

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m >> k;
    cin >> s >> t;
    vi sum(n);
    For(ic, 0, 4){
        vi a, b;
        For(i, 0, n){
            a.emplace_back(s[i] == c[ic] ? 1 : 0);
        }
        FordE(j, m - 1, 0){
            b.emplace_back(t[j] == c[ic] ? 1 : 0);
        }
        set <int> stt;
        For(i, 0, n){
            if (a[i]){
                stt.insert(i);
            }
        }
        For(i, 0, n){
            if (!a[i]){
                if (stt.lower_bound(i) != stt.end()){
                    int j = *stt.lower_bound(i);
                    if (j - i <= k){
                        a[i] = 1;
                    }
                }
                if (stt.lower_bound(i) != stt.begin()){
                    int j = *(--stt.lower_bound(i));
                    if (i - j <= k){
                        a[i] = 1;
                    }
                }
            }
        }
        vi c = convolute(a, b);
        For(i, m - 1, n + m - 1){
            sum[i - m + 1] += c[i];
        }
    }
    int ans = 0;
    For(i, 0, n){
        if (sum[i] == m){
            ans++;
        }
    }
    cout << ans << endl;
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