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

int n;
pii a[N], b[N];

void readTest(){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i].fi >> a[i].se;
        cin >> b[i].fi >> b[i].se;
    }
}

map <pii, pii> mpp;
ll ans;

void resetTest(){
    mpp.clear();
    ans = 0;
}

void solveTest(){
    ForE(i, 1, n){
        int dx = a[i].fi - b[i].fi, dy = a[i].se - b[i].se;
        int g = abs(__gcd(dx, dy)); dx /= g; dy /= g;
        if (dx < 0 || (dx == 0 && dy < 0)){
            mpp[{-dx, -dy}].se++;
        }
        else{
            mpp[{dx, dy}].fi++;
        }
    }
    Fora(&v, mpp){
        ans += (ll)v.se.fi * v.se.se;
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    readTest();
    resetTest();
    solveTest();
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