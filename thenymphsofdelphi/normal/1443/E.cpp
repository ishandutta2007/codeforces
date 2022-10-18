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

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
int randt(int l, int r){ return rando() % (r - l + 1) + l; }

const int N = 2e5 + 5, M = 15 + 1;

int n, q;
int tn;
ll fac[M];
int a[M], b[M];
ll cnt = 1;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    fac[0] = 1;
    For(i, 1, M){
        fac[i] = fac[i - 1] * i;
    }
    cin >> n >> q;
    tn = min(n, M - 1);
    ForE(i, 1, tn){
        a[tn - i + 1] = n - i + 1;
    }
    ForE(i, 1, tn){
        b[i] = a[i];
    }
    while (q--){
        int que; cin >> que;
        if (que == 1){
            int l, r; cin >> l >> r;
            ll sum = 0;
            if (r <= n - tn){
                sum = (ll)r * (r + 1) / 2 - (ll)(l - 1) * l / 2;
            }
            else{
                if (l <= n - tn){
                    sum = (ll)(n - tn) * (n - tn + 1) / 2 - (ll)(l - 1) * l / 2;
                    l = n - tn + 1;
                }
                ForE(i, l, r){
                    sum += a[i - (n - tn)];
                }
            }
            cout << sum << endl;
        }
        else{
            int x; cin >> x;
            cnt += x;
            ll tcnt = cnt;
            vi c;
            ForE(i, 1, tn){
                c.push_back(b[i]);
            }
            ForE(i, 1, tn){
                int j = 0;
                while (tcnt > fac[tn - i]){
                    tcnt -= fac[tn - i]; j++;
                }
                a[i] = c[j];
                c.erase(c.begin() + j);
            }
        }
    }
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |

------------------------------    |
==================================+
*/