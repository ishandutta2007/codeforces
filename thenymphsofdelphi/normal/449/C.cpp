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

mt19937_64 rando(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5 + 5;

int n;
vi prime;
int lpf[N];

void sieve(){
    ForE(i, 2, n){
        if (!lpf[i]){
            lpf[i] = i;
            prime.push_back(i);
        }
        for (int j = 0; j < isz(prime) && prime[j] <= i && prime[j] * i <= n; j++){
            lpf[prime[j] * i] = prime[j];
        }
    }
}

int posprime[N];
vpii ans;

bool ck[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> n;
    if (n == 1){
        cout << 0 << endl;
        return 0;
    }
    sieve();
    reverse(bend(prime)); prime.pop_back();
    Fora(&v, prime){
        int x = 0;
        for (int j = v; j <= n; j += v){
            if (!ck[j]){
                x++;
            }
        }
        if (x == 1){
            continue;
        }
        int y = -1;
        for (int j = v; j <= n; j += v){
            if (!ck[j]){
                if (j == v * 2 && x % 2 == 1){
                    continue;
                }
                if (y == -1){
                    y = j;
                }
                else{
                    ans.emplace_back(y, j);
                    ck[y] = ck[j] = 1;
                    y = -1;
                }
            }
        }
        continue;
    }
    int y = -1;
    for (int j = 2; j <= n; j += 2){
        if (!ck[j]){
            if (y == -1){
                y = j;
            }
            else{
                ans.emplace_back(y, j);
                    ck[y] = ck[j] = 1;
                y = -1;
            }
        }
    }
    cout << isz(ans) << endl;
    Fora(&v, ans){
        cout << v.fi << ' ' << v.se << endl;
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