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

const int N = 5e5 + 5;

int n, m; ll k;
int a[N], b[N];
int posb[2 * N];
vector <ll> c;

ll egcd(ll a, ll b, ll &x, ll &y){
    if (a == 0){
        x = 0;
        y = 1;
        return b;
    }
    ll x1, y1, d = egcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    memset(posb, -1, sizeof(posb));
    cin >> n >> m >> k;
    For(i, 0, n){
        cin >> a[i];
    }
    For(i, 0, m){
        cin >> b[i];
        posb[b[i]] = i;
    }
    ll x, y, g = egcd(n, m, x, y); // nx + my = 1
    For(i, 0, n){
        if (posb[a[i]] == -1){
            continue;
        }
        int j = posb[a[i]];
        if (i % g == j % g){
            c.push_back(0);
            c.back() = m / g * i * y + n / g * j * x;
            c.back() %= n / g * m;
            if (c.back() < 0){
                c.back() += n / g * m;
            }
        }
        else{
            continue;
        }
    }
    ll l = 1, r = (ld)1e18 + 7;
    while (l < r){
        ll mid = (l + r) >> 1;
        ll t = mid;
        Fora(&v, c){
            if (mid <= v){
                continue;
            }
            t -= (mid - v - 1) / (n / g * m) + 1;
        }
        if (t >= k){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << l << endl;
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