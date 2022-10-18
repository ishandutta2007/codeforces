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

int n, m;
int a[N][N];
int b[N][N]; // prefix sum of row

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    cin >> n >> m;
    ForE(i, 1, n){
        ForE(j, 1, m){
            char c; cin >> c; a[i][j] = (c == '*');
            b[i][j] = b[i][j - 1] + a[i][j];
        }
    }
    int ans = 0;
    ForE(i, 1, n){
        ForE(j, 1, m){
            ForE(k, 1, n){
                if (i + k - 1 > n || j - k + 1 < 1 || j + k - 1 > m){
                    break;
                }
                if (b[i + k - 1][j + k - 1] - b[i + k - 1][j - k + 1 - 1] != (j + k - 1) - (j - k + 1) + 1){
                    break;
                }
                ans++;
            }
        }
    }
    cout << ans << endl;
}
}