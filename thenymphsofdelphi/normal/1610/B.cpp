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

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 2e5 + 5;

int n;
int a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    int l = 1, r = n;
    bool ans = 0;
    while (l < r){
        if (a[l] == a[r]){
            l++; r--;
            continue;
        }
        {
            int tl = l, tr = r;
            while (tl < tr){
                if (a[tl] == a[l]){
                    tl++;
                    continue;
                }
                if (a[tr] == a[l]){
                    tr--;
                    continue;
                }
                if (a[tl] == a[tr]){
                    tl++; tr--;
                    continue;
                }
                break;
            }
            if (tl >= tr){
                ans = 1;
            }
        }
        {
            int tl = l, tr = r;
            while (tl < tr){
                if (a[tl] == a[r]){
                    tl++;
                    continue;
                }
                if (a[tr] == a[r]){
                    tr--;
                    continue;
                }
                if (a[tl] == a[tr]){
                    tl++; tr--;
                    continue;
                }
                break;
            }
            if (tl >= tr){
                ans = 1;
            }
        }
        break;
    }
    if (l >= r){
        ans = 1;
    }
    if (ans){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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