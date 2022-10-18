#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
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

const int N = 5e4 + 5;

int n, m, k;
int a[N], b[N];

pii caca[N], cacb[N];
vpii ra, rb;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n >> k;
    ForE(i, 1, n){
        cin >> a[i];
    }
    cin >> m;
    ForE(i, 1, m){
        cin >> b[i];
    }

    ForE(i, 1, n){
        caca[i] = make_pair(a[i], 1);
        while (caca[i].fi % k == 0){
            caca[i].fi /= k; caca[i].se *= k;
        }
    }
    ForE(i, 1, m){
        cacb[i] = make_pair(b[i], 1);
        while (cacb[i].fi % k == 0){
            cacb[i].fi /= k; cacb[i].se *= k;
        }
    }

    ra.clear(); rb.clear();
    {
        int val = caca[1].fi, cnt = caca[1].se;
        ForE(i, 2, n + 1){
            if (i == n + 1 or caca[i].fi != caca[i - 1].fi){
                ra.emplace_back(val, cnt);
                val = caca[i].fi; cnt = caca[i].se;
            }
            else{
                cnt += caca[i].se;
            }
        }
    }
    {
        int val = cacb[1].fi, cnt = cacb[1].se;
        ForE(i, 2, m + 1){
            if (i == m + 1 or cacb[i].fi != cacb[i - 1].fi){
                rb.emplace_back(val, cnt);
                val = cacb[i].fi; cnt = cacb[i].se;
            }
            else{
                cnt += cacb[i].se;
            }
        }
    }

    if (ra == rb){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
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