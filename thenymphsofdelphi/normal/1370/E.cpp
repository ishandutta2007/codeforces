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

int n, ans, sum, tmp;
string s, t;
int cnts, cntt;

int a[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
// int q; cin >> q; while (q--){
    cin >> n;
    cin >> s; s = ' ' + s;
    cin >> t; t = ' ' + t;
    Fora(&v, s){
        if (v == '1'){
            cnts++;
        }
    }
    Fora(&v, t){
        if (v == '1'){
            cntt++;
        }
    }
    if (cnts != cntt){
        cout << -1 << endl;
        return 0;
    }
    ForE(i, 1, n){
        a[i] = s[i] - t[i];
    }
    sum = 0; tmp = 0;
    ForE(i, 1, n){
        sum += a[i];
        ans = max(ans, abs(sum - tmp));
        tmp = min(tmp, sum);
    }
    sum = 0; tmp = 0;
    ForE(i, 1, n){
        sum += a[i];
        ans = max(ans, abs(sum - tmp));
        tmp = max(tmp, sum);
    }
    cout << ans << endl;
// }
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