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

const int N = 1e5 + 5;



signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
int q; cin >> q; while (q--){
    int px, py; cin >> px >> py;
    int x = 0, y = 0;
    string s; cin >> s;
    Fora(&v, s){
        if (px > 0 && v == 'R'){
            x++;
        }
        if (px < 0 && v == 'L'){
            x++;
        }
        if (py > 0 && v == 'U'){
            y++;
        }
        if (py < 0 && v == 'D'){
            y++;
        }
    }
    if (x >= abs(px) && y >= abs(py)){
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