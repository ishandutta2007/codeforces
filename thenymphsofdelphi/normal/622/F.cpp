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

#define div __div__

const int N = 1e6 + 5, mod = 1e9 + 7;

int add(int x, int y){
    x += y; if (x >= mod) x -= mod; return x;
}

int sub(int x, int y){
    x -= y; if (x < 0) x += mod; return x;
}

int mul(int x, int y){
    return 1ll * x * y % mod;
}

int binpow(int x, int y){
    int ans = 1;
    while (y){
        if (y & 1) ans = mul(ans, x);
        x = mul(x, x);
        y >>= 1;
    }
    return ans;
}

int inv(int x){
    return binpow(x, mod - 2);
}

int div(int x, int y){
    return mul(x, inv(y));
}

int n, k;

int a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    ForE(i, 1, k + 2){
        a[i] = binpow(i, k);
    }
    ForE(i, 2, k + 2){
        a[i] = add(a[i - 1], a[i]);
    }
    if (n <= k + 2){
        cout << a[n] << endl;
        return 0;
    }
    int ans = 0, nume = 1, deno = 1;
    ForE(i, 1, k + 2){
        nume = mul(nume, n - i);
    }
    ForE(i, 1, k + 1){
        deno = mul(deno, sub(0, i));
    }
    ForE(i, 1, k + 2){
        ans = add(ans, mul(a[i], div(div(nume, n - i), deno)));
        if (i != k + 2){
            deno = div(deno, sub(0, k + 2 - i));
            deno = mul(deno, i);
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