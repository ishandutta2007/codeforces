#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int M = 512;
const int N = 1e5 + 10;
//last, xor
int dp[M][M], a[N], nxt[M][N];
vector<int> have[M];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int vl = 0; vl < M; vl++) {
        nxt[vl][n] = 1e9;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == vl) {
                nxt[vl][i] = i;
            } else {
                nxt[vl][i] = nxt[vl][i + 1];
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            dp[i][j] = 1e9;
        }
    }
    dp[0][0] = 0;
    set<int> ok;
    ok.insert(0);
    for (int last = 1; last < M; last++) {
        for (int xor_v = 0; xor_v < M; xor_v++) {
            for (int pred = last - 1; pred >= 0; pred--) {
                if (dp[pred][xor_v ^ last] < 1e9) {
                    dp[last][xor_v] = min(dp[last][xor_v], nxt[last][dp[pred][xor_v ^ last]]);
                }
            }
            if (dp[last][xor_v] < 1e9) {
                ok.insert(xor_v);
            }
        }
    }
    cout << SZ(ok) << '\n';
    for (auto it : ok) {
        cout << it << ' ';
    }
    cout << '\n';
}