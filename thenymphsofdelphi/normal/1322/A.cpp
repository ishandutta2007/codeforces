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

const int N = 1e6 + 5;

int n;
string s;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> n;
    cin >> s;
    int bal = 0;
    Fora(&v, s){
        if (v == '(') bal++;
        else bal--;
    }
    if (bal){
        cout << -1 << endl;
        return 0;
    }
    int ans = 0, len = 0, ck = 0; bal = 0;
    Fora(&v, s){
        if (v == '(') bal++;
        else bal--;
        if (bal < 0 && !ck){
            ck = 1;
        }
        if (ck){
            len++;
        }
        if (ck && !bal){
            ck = 0;
            ans += len;
            len = 0;
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