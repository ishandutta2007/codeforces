#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

const int N = 1e5 + 5;

int n, m;
int p[N], type[N];
bool ck[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    cin >> n >> m;
    ForE(i, 1, n){
        p[i] = 0; ck[i] = 0; type[i] = 0;
    }
    ForE(i, 1, m){
        int x, y; cin >> x >> y;
        p[x] = y;
    }
    int ans = m;
    ForE(i, 1, n){
        if (p[i] && !ck[i]){
            int x = i; ck[i] = 1;
            while (p[x] && !ck[p[x]]){
                x = p[x]; ck[x] = 1;
            }
            if (!p[x] || type[p[x]] == 1){
                type[i] = 1;
                continue;
            }
            if (p[i] == i){
                ans--;
            }
            else{
                ans++;
            }
        }
    }
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