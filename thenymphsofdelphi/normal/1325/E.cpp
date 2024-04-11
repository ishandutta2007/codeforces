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

const int N = 1e5 + 5, M = 1e6 + 5;

int lpf[M];
vi prime;

void sieve(){
    For(i, 2, M){
        if (!lpf[i]){
            lpf[i] = i;
            prime.push_back(i);
        }
        for (int j = 0; j < isz(prime) and prime[j] <= i and prime[j] * i < M; j++){
            lpf[prime[j] * i] = prime[j];
        }
    }
}

int n, ans = N;
pii a[N];
vi adj[M];

int par[M], h[M];

void bfs(int r){
    queue <int> qu;
    par[r] = -1; h[r] = 1; qu.push(r);
    while (!qu.empty()){
        int u = qu.front(); qu.pop();
        Fora(&v, adj[u]){
            if (!h[v]){
                par[v] = u;
                h[v] = h[u] + 1;
                qu.push(v);
            }
            else if (v != par[u]){
                ans = min(ans, h[u] + h[v] - 1);
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    sieve();
    cin >> n;
    ForE(i, 1, n){
        int x; cin >> x;
        if (x == 1){
            cout << 1 << endl;
            return 0;
        }
        map <int, int> mpp;
        while (x != 1){
            mpp[lpf[x]]++;
            x /= lpf[x];
        }
        bool ck = 1;
        Fora(&elem, mpp){
            elem.se %= 2;
            if (elem.se == 1){
                ck = 0;
            }
        }
        if (ck){
            cout << 1 << endl;
            return 0;
        }
        Fora(&elem, mpp){
            if (elem.se == 1){
                if (!a[i].fi){
                    a[i].fi = elem.fi;
                }
                else{
                    a[i].se = elem.fi;
                    if (a[i].fi > a[i].se){
                        swap(a[i].fi, a[i].se);
                    }
                }
            }
        }
    }
    sort(a + 1, a + 1 + n);
    ForE(i, 2, n){
        if (a[i] == a[i - 1]){
            cout << 2 << endl;
            return 0;
        }
    }
    ForE(i, 1, n){
        if (a[i].se == 0){
            adj[1].push_back(a[i].fi);
            adj[a[i].fi].push_back(1);
        }
        else{
            adj[a[i].fi].push_back(a[i].se);
            adj[a[i].se].push_back(a[i].fi);
        }
    }
    ForE(i, 2, 1000){
        if (lpf[i] != i){
            continue;
        }
        par[1] = h[1] = 0;
        Fora(&v, prime){
            par[v] = h[v] = 0;
        }
        bfs(i);
    }
    if (ans == N){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
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