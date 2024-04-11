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

const int N = 2e5 + 5, mod = 1e9 + 7;

int n, q;
string s;

int cnt;

bool check(int idx){
    return s[idx - 1] == 'a' and s[idx] == 'b' and s[idx + 1] == 'c';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> q;
    cin >> s; s = ' ' + s;
    For(i, 2, n){
        if (check(i)){
            cnt++;
        }
    }
    while (q--){
        int idx; char c; cin >> idx >> c;
        if (1 < idx and idx < n){
            cnt -= check(idx);
        }
        if (1 < idx - 1 and idx - 1 < n){
            cnt -= check(idx - 1);
        }
        if (1 < idx + 1 and idx + 1 < n){
            cnt -= check(idx + 1);
        }
        s[idx] = c;
        if (1 < idx and idx < n){
            cnt += check(idx);
        }
        if (1 < idx - 1 and idx - 1 < n){
            cnt += check(idx - 1);
        }
        if (1 < idx + 1 and idx + 1 < n){
            cnt += check(idx + 1);
        }
        cout << cnt << endl;
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