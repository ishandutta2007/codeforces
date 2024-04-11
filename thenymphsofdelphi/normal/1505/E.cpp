#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
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

const int N = 5 + 5;

int n, m, ans;
char a[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, n){
        ForE(j, 1, m){
            cin >> a[i][j];
        }
    }
    int x = 1, y = 1;
    while (x != n or y != m){
        priority_queue <pair <pii, pii>, vector <pair <pii, pii>>, greater <pair <pii, pii>>> pq;
        ForE(i, x, n){
            ForE(j, y, m){
                if (a[i][j] == '*'){
                    pq.push(make_pair(make_pair(i - x + j - y, i), make_pair(i, j)));
                }
            }
        }
        if (pq.empty()){
            break;
        }
        ans++; x = pq.top().se.fi; y = pq.top().se.se;
        a[x][y] = '.';
    }
    cout << ans << endl;
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/