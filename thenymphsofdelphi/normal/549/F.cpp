#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 3e5 + 5, M = 1e6 + 5, LN = 19;

int n, k;
int a[N];

int b[N], pb[N];

pii sptb[LN][N];

pii rmq(int l, int r){
    int z = __lg(r - l + 1);
    return max(sptb[z][l], sptb[z][r - (1 << z) + 1]);
}

struct query_t{
    int l, r, x, ans = 0;

    query_t(int l, int r, int x): l(l), r(r), x(x){

    }
};

vector <query_t> c;
vi d[N];

void pre_dnc(int l, int r){
    int m = rmq(l, r).se;
    if (m - l + 1 >= r - m + 1){
        ForE(i, m, r){
            c.emplace_back(l - 1, m - 1, (pb[i] - b[m] + k) % k);
            d[c.back().l - 1].emplace_back(isz(c) - 1);
            d[c.back().r].emplace_back(isz(c) - 1);
        }
    }
    else{
        ForE(i, l, m){
            c.emplace_back(m, r, (pb[i - 1] + b[m]) % k);
            d[c.back().l - 1].emplace_back(isz(c) - 1);
            d[c.back().r].emplace_back(isz(c) - 1);
        }
    }

    if (l < m){
        pre_dnc(l, m - 1);
    }
    if (m < r){
        pre_dnc(m + 1, r);
    }
}

int cnt[M];

int itrc = 0;
ll ans;

void dnc(int l, int r){
    int m = rmq(l, r).se;
    if (m - l + 1 >= r - m + 1){
        ForE(i, m, r){
            ans += c[itrc++].ans;
        }
    }
    else{
        ForE(i, l, m){
            ans += c[itrc++].ans;
        }
    }

    if (l < m){
        dnc(l, m - 1);
    }
    if (m < r){
        dnc(m + 1, r);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    ForE(i, 1, n){
        cin >> a[i];
    }

    ForE(i, 1, n){
        b[i] = a[i] % k;
        pb[i] = pb[i - 1] + b[i];
        if (pb[i] >= k){
            pb[i] -= k;
        }
    }
    ForE(i, 1, n){
        sptb[0][i] = make_pair(a[i], i);
    }
    For(j, 1, LN){
        ForE(i, 1, n - (1 << j) + 1){
            sptb[j][i] = max(sptb[j - 1][i], sptb[j - 1][i + (1 << (j - 1))]);
        }
    }

    pre_dnc(1, n);
    ForE(i, 0, n){
        cnt[pb[i]]++;
        Fora(idx, d[i]){
            if (i == c[idx].l - 1){
                c[idx].ans -= cnt[c[idx].x];
            }
            else{
                c[idx].ans += cnt[c[idx].x];
            }
        }
    }
    dnc(1, n);
    cout << ans - n << endl;
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