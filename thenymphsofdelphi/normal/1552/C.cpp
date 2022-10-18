#include <bits/stdc++.h>
using namespace std;

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

const int N = 2e2 + 5, mod = 1e9 + 7;

int n, k;
int x[N], y[N];

bool ck[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int q; cin >> q; while (q--){
    cin >> n >> k;
    ForE(i, 1, k){
        cin >> x[i] >> y[i];
    }

    ForE(i, 1, 2 * n){
        ck[i] = 0;
    }
    ForE(i, 1, k){
        ck[x[i]] = ck[y[i]] = 1;
    }
    vi a;
    ForE(i, 1, 2 * n){
        if (!ck[i]){
            a.emplace_back(i);
        }
    }
    ForE(i, k + 1, n){
        x[i] = a[i - (k + 1)];
        y[i] = a[i - (k + 1) + (n - k)];
    }
    ForE(i, 1, n){
        if (x[i] > y[i]){
            swap(x[i], y[i]);
        }
    }
    int ans = 0;
    ForE(i, 1, n){
        ForE(j, i + 1, n){
            int t = (x[i] <= x[j] and x[j] <= y[i] ? 1 : 0) + (x[i] <= y[j] and y[j] <= y[i] ? 1 : 0);
            if (t == 1){
                ans++;
            }
        }
    }
    cout << ans << endl;
}
}

/*
==================================================+
INPUT                                             |
--------------------------------------------------+

--------------------------------------------------+
==================================================+
OUTPUT                                            |
--------------------------------------------------+

--------------------------------------------------+
==================================================+
*/