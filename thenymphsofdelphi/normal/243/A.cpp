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

const int N = 1e5 + 5, M = (1 << 20), LN = 17;

int n;
int a[N];

int sptb[LN][N];

int query(int l, int r){
    int z = __lg(r - l + 1);
    return sptb[z][l] | sptb[z][r - (1 << z) + 1];
}

bool ck[M];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }

    ForE(i, 1, n){
        sptb[0][i] = a[i];
    }
    For(j, 1, LN){
        ForE(i, 1, n - (1 << j) + 1){
            sptb[j][i] = sptb[j - 1][i] | sptb[j - 1][i + (1 << (j - 1))];
        }
    }
    ForE(l, 1, n){
        int idx = l, val = a[idx];
        while (idx <= n){
            int lo = idx, hi = n + 1;
            while (lo < hi){
                int mid = (lo + hi) >> 1;
                if (query(l, mid) == val){
                    lo = mid + 1;
                }
                else{
                    hi = mid;
                }
            }
            ck[val] = 1;
            idx = lo;
            val |= a[idx];
        }
    }
    cout << accumulate(ck, ck + M, 0) << endl;
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