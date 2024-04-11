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

const int N = 2e5 + 5;

int n;
int a[N];

int ans;

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

    ans = 1;
    ForE(i, 1, n){
        if (a[i] == a[n]){
            ans = max(ans, n - i + 1);
            continue;
        }
        if (a[i] == a[i - 1]){
            continue;
        }
        int idx = i, tans = 1;
        while (a[idx] == a[i]){
            idx++; tans++;
        }
        while (1){
            int nidx = lower_bound(a + 1, a + n + 1, 2 * a[idx] - a[i]) - a;
            if (nidx <= n){
                idx = nidx;
                tans++;
            }
            else{
                break;
            }
        }
        ans = max(ans, tans);
    }
    cout << n - ans << endl;
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