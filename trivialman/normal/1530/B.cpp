#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 998244353;
const LL INF = 1e18;
const int N = 22;
mt19937 rng(time(0));

int T, n,m;
char s[N][N];

int main() {
    cin >> T;
    while(T--){
        cin >> n >> m;
        rep(i, 1, n) rep(j, 1, m) s[i][j] = '0';
        rep(i, 1, n) s[i][m + 1] = 0;
        s[1][1] = s[1][m] = s[n][1] = s[n][m] = '1';
        for (int i = 3; i <= m - 2;i+=2)
            s[1][i] = s[n][i] = '1';
        for (int i = 3; i <= n - 2; i += 2)
            s[i][1] = s[i][m] = '1';
        rep(i, 1, n) cout << (s[i]+1) << endl;
        cout << endl;
    }
    return 0;
}