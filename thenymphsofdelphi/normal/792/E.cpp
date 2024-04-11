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

const int N = 5e2 + 5;

int n;
int a[N];

vi candidates;
ll ans = (ld)1e18 + 7;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    int s = 0;
    for (int b = 1; b * b <= a[1]; b++){
        s = b;
        candidates.emplace_back(b);
    }
    for (int q = 1; q * q <= a[1]; q++){
        int b = a[1] / q;
        if (b <= s){
            continue;
        }
        candidates.emplace_back(b);
        if (!(a[1] % q) and b - 1 > s){
            candidates.emplace_back(b - 1);
        }
    }
    Fora(&b, candidates){
        ll tans = 0;
        ForE(i, 1, n){
            int q = a[i] / b - (a[i] / b - a[i] % b) / (b + 1);
            int r = a[i] - b * q;
            if (0 <= r and r <= q){
                tans += q;
            }
            else{
                tans = -1;
                break;
            }
        }
        if (tans >= 0){
            ans = min(ans, tans);
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