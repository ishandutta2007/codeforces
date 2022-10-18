#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long

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

const int N = 2e5 + 5, mod = 998244353;

int n;
int a[N];
ll b[N], c[2][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int q; cin >> q; while (q--){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        b[i] = b[i - 1] + a[i];
        c[0][i] = c[0][i - 1]; c[1][i] = c[1][i - 1];
        if (i % 2){
            c[1][i] += a[i];
        }
        else{
            c[0][i] += a[i];
        }
    }
    ll ans = 0;
    ForE(i, 1, n){
        ll sum = b[n] - 2 * b[i - 1];
        int r1 = -1, r2 = -1;
        if (sum > 0){
            // cout << "A " << i << ' ' << sum << endl;
            ans++;
            int idx = lower_bound(c[(i + 1) % 2] + 1, c[(i + 1) % 2] + 1 + n, (sum + 1) / 2 + c[(i + 1) % 2][i - 1]) - c[(i + 1) % 2];
            r1 = idx;
            // cout << "A " << idx << endl;
            ans += max(0ll, idx - i) / 2;
        }
        if (i >= 4){
            sum += 2 * a[1];
            if (sum > 0){
                // cout << "B " << i << ' ' << sum << endl;
                ans++;
                int idx = lower_bound(c[(i + 1) % 2] + 1, c[(i + 1) % 2] + 1 + n, (sum + 1) / 2 + c[(i + 1) % 2][i - 1]) - c[(i + 1) % 2];
                r2 = idx;
                // cout << "B " << idx << endl;
                ans += max(0ll, idx - i) / 2;
            }
            sum -= 2 * a[1];
        }
        if (i < n){
            sum -= 2 * a[n];
            if (sum > 0){
                // cout << "C " << i << ' ' << sum << endl;
                ans++;
                if (i == n - 1 and r1 == n + 1){
                    ans--;
                }
                int idx = lower_bound(c[(i + 1) % 2] + 1, c[(i + 1) % 2] + 1 + n, (sum + 1) / 2 + c[(i + 1) % 2][i - 1]) - c[(i + 1) % 2];
                ans += max(0ll, idx - i) / 2;
                if ((i + 1) % 2 == n % 2 and idx == n + 1 and r1 == n + 1 and i <= n - 1){
                    ans--;
                }
                if ((i + 1) % 2 == n % 2 and idx >= n and r1 == n + 1 and i <= n - 3){
                    ans--;
                }
                if ((i + 1) % 2 != n % 2 and idx == n + 1 and i <= n - 2){
                    ans--;
                }
                // cout << "C " << idx << endl;
            }
            sum += 2 * a[n];
        }
        if (i >= 4 and i < n){
            sum += 2 * a[1];
            sum -= 2 * a[n];
            if (sum > 0){
                // cout << "D " << i << ' ' << sum << endl;
                ans++;
                if (i == n - 1 and r2 == n + 1){
                    ans--;
                }
                int idx = lower_bound(c[(i + 1) % 2] + 1, c[(i + 1) % 2] + 1 + n, (sum + 1) / 2 + c[(i + 1) % 2][i - 1]) - c[(i + 1) % 2];
                ans += max(0ll, idx - i) / 2;
                if ((i + 1) % 2 == n % 2 and idx == n + 1 and r2 == n + 1 and i <= n - 1){
                    ans--;
                }
                if ((i + 1) % 2 == n % 2 and idx >= n and r2 == n + 1 and i <= n - 3){
                    ans--;
                }
                if ((i + 1) % 2 != n % 2 and idx == n + 1 and i <= n - 2){
                    ans--;
                }
                // cout << "D " << idx << endl;
            }
            sum -= 2 * a[1];
            sum += 2 * a[n];
        }
    }
    For(i, 2, n){
        ll sum = 2 * b[i - 1] - b[n];
        if (sum > 0){
            ans++;
        }
    }
    cout << ans % mod << endl;
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