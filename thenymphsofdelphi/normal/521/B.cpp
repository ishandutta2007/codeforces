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

const int N = 1e5 + 5, mod = 1e9 + 9;

inline void sadd(int& x, int y){
    if ((x += y) >= mod) x -= mod;
    return;
}

inline int add(int x, int y){
    if ((x += y) >= mod) x -= mod;
    return x;
}

inline void ssub(int& x, int y){
    if ((x -= y) < 0) x += mod;
    return;
}

inline int sub(int x, int y){
    if ((x -= y) < 0) x += mod;
    return x;
}

inline int mul(int x, int y){
    return 1ll * x * y % mod;
}

inline int binpow(int x, int y){
    int ans = 1;
    while (y){
        if (y & 1) ans = mul(ans, x);
        x = mul(x, x);
        y >>= 1;
    }
    return ans;
}

inline int inv(int x){
    return binpow(x, mod - 2);
}

#define div __div__
inline int div(int x, int y){
    return mul(x, binpow(y, mod - 2));
}

int fac[N], invfac[N];

void calfac(){
    fac[0] = invfac[0] = 1;
    For(i, 1, N){
        fac[i] = mul(fac[i - 1], i);
    }
    invfac[N - 1] = binpow(fac[N - 1], mod - 2);
    FordE(i, N - 2, 1){
        invfac[i] = mul(invfac[i + 1], i + 1);
    }
}

inline int C(int n, int k){
    if (n < 0 or k < 0 or k > n){
        return 0;
    }
    return mul(fac[n], mul(invfac[k], invfac[n - k]));
}

inline int P(int n, int k){
    if (n < 0 or k < 0 or k > n){
        return 0;
    }
    return mul(fac[n], invfac[n - k]);
}

struct cube_t{
    int x, y, idx;

    cube_t(){

    }
};

int n;
cube_t a[N];

map <pii, int> mpp;

vi down[N]; vi up[N];
int need[N], needed[N];

set <int> sttfree;

int ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i].x >> a[i].y; a[i].idx = i;
    }

    ForE(i, 1, n){
        mpp[make_pair(a[i].x, a[i].y)] = a[i].idx;
    }
    ForE(i, 1, n){
        ForE(dx, -1, 1){
            if (mpp.count(make_pair(a[i].x + dx, a[i].y - 1))){
                int j = mpp[make_pair(a[i].x + dx, a[i].y - 1)];
                down[i].emplace_back(j);
                up[j].emplace_back(i);
            }
        }
        if (isz(down[i]) == 1){
            need[i]++; needed[down[i][0]]++;
        }
    }
    ForE(i, 1, n){
        if (needed[i] == 0){
            sttfree.emplace(i);
        }
    }
    int side = 1;
    ForE(turn, 1, n){
        int i = -1;
        if (side == 1){
            i = *prev(sttfree.end());
        }
        else{
            i = *sttfree.begin();
        }
        sttfree.erase(i);
        ans = add(mul(ans, n), i - 1);
        Fora(j, down[i]){
            up[j].erase(find(bend(up[j]), i));
        }
        Fora(j, up[i]){
            down[j].erase(find(bend(down[j]), i));
            if (isz(down[j]) == 1){
                need[j]++;
                if (needed[down[j][0]] == 0){
                    sttfree.erase(down[j][0]);
                }
                needed[down[j][0]]++;
            }
        }
        if (need[i]){
            needed[down[i][0]]--;
            if (needed[down[i][0]] == 0){
                sttfree.emplace(down[i][0]);
            }
        }
        side = 1 - side;
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