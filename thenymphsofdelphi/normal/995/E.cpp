#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
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

int s, t, mod;

int binpow(int x, int y){
    int ans = 1;
    while (y){
        if (y & 1) ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}

vi cal(int u){
    vi vans;
    if (!u){
        vans.emplace_back(2);
        u = mod - 1;
    }
    int k = randt(1, mod - 1);
    int x = u * k % mod, y = k;
    while (x != y){
        if (x > y){
            vans.emplace_back(2);
            x -= y;
        }
        else{
            vans.emplace_back(3);
            swap(x, y);
        }
        if (isz(vans) > 100){
            return vans;
        }
    }
    return vans;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> s >> t >> mod;
    vi a;
    do{
        a = cal(s);
    } while (isz(a) > 100);
    vi b;
    do{
        b = cal(t);
    } while (isz(b) > 100);
    reverse(bend(b));
    cout << isz(a) + isz(b) << endl;
    Fora(&v, a){
        cout << v << ' ';
    }
    Fora(&v, b){
        cout << (v == 2 ? 1 : 3) << ' ';
    }
    cout << endl;
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