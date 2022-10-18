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

const int N = 1e2 + 5;

int n, m;
int a[N][N], idx[N], ans[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int q; cin >> q; while (q--){
    cin >> n >> m;
    priority_queue <pii, vpii, greater <pii>> qu;
    ForE(i, 1, n){
        ForE(j, 1, m){
            cin >> a[i][j];
            ans[i][j] = 0;
        }
        sort(a[i] + 1, a[i] + 1 + m);
        ForE(j, 1, m){
            qu.push(make_pair(a[i][j], i));
        }
    }
    ForE(i, 1, n){
        idx[i] = 1;
    }
    ForE(j, 1, m){
        int i = qu.top().se; qu.pop();
        ans[i][j] = a[i][idx[i]];
        idx[i]++;
    }
    ForE(i, 1, n){
        ForE(j, 1, m){
            if (!ans[i][j]){
                ans[i][j] = a[i][idx[i]];
                idx[i]++;
            }
            cout << ans[i][j] << ' ';
        } cout << endl;
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