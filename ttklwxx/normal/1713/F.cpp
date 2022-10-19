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

const int N = 1 << 19;

int n;
int a[N], b[N], ta[N], tb[N];
int c[N];

int m, lm, all1;

signed main(){
    cin >> n;
    ForE(i, 1, n){
        cin >> b[i];
    }

    m = 1 << __lg(n);
    if (m < n){
        m *= 2;
    }
    lm = __lg(m);
    all1 = m - 1;
    memset(ta, -1, sizeof(ta));
    memset(tb, -1, sizeof(tb));
    ForE(i, 1, n){
        tb[all1 ^ (i - 1)] = b[i];
        ta[n - i] = -2;
    }

    For(i, 0, m){
        c[all1 ^ i] = max(tb[i], 0);
    }
    For(bit, 0, lm){
        For(msk, 0, m){
            if (msk >> bit & 1){
                c[msk] ^= c[msk ^ (1 << bit)];
            }
        }
    }
    For(i, 0, m){
        if (tb[i] == -1){
            c[all1 ^ i] = 0;
        }
    }
    For(bit, 0, lm){
        For(msk, 0, m){
            if (msk >> bit & 1){
                c[msk] ^= c[msk ^ (1 << bit)];
            }
        }
    }
    For(i, 0, m){
        if (tb[i] == -1){
            tb[i] = c[all1 ^ i];
        }
    }

    For(i, 0, m){
        ta[i] = tb[i];
    }
    For(bit, 0, lm){
        For(msk, 0, m){
            if (msk >> bit & 1){
                ta[msk] ^= ta[msk ^ (1 << bit)];
            }
        }
    }
    ForE(i, 1, n){
        a[i] = ta[n - i];
    }
    ForE(i, 1, n){
        cout << a[i] << ' ';
    } cout << endl;
}