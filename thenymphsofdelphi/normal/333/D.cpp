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

const int N = 1e3 + 5;

int n, m;
int a[N][N];

bool b[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, n){
        ForE(j, 1, m){
            cin >> a[i][j];
        }
    }

    int lo = 0, hi = 1000000000;
    while (lo < hi){
        int mid = (lo + hi + 1) >> 1;

        ForE(j1, 1, m){
            ForE(j2, j1 + 1, m){
                b[j1][j2] = 0;
            }
        }
        bool ck = 0;
        ForE(i, 1, n){
            vi c;
            ForE(j, 1, m){
                if (a[i][j] >= mid){
                    c.emplace_back(j);
                }
            }
            For(j1, 0, isz(c)){
                For(j2, j1 + 1, isz(c)){
                    if (b[c[j1]][c[j2]]){
                        ck = 1;
                        break;
                    }
                    b[c[j1]][c[j2]] = 1;
                }
                if (ck){
                    break;
                }
            }
            if (ck){
                break;
            }
        }
        if (ck){
            lo = mid;
        }
        else{
            hi = mid - 1;
        }
    }
    cout << lo << endl;
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