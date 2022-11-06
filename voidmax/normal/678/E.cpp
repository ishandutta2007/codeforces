#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

string FileName = "input";

typedef double base;

const int Size = 1 << 18;
base ans[Size][18];
base arr[18][18];
int n;

int main() {
    cin >> n;
    For(i, 0, n) For(j, 0, n) cin >> arr[i][j];
    ans[(1 << n) - 1][0] = 1;
    Out(i, (1 << n), 0) {
        vector <int> b[2];
        For(j, 0, n) {
            if (i & (1 << j)) {
                b[0].pb(j);
            } else {
                b[1].pb(j);
            }
        }
        for(int j: b[0]) {
            for (int k: b[1]) {
                int m = i + (1 << k);
                //cout << i << ' ' << j << ' ' << k << ' ' << ans[m][j] * arr[j][k] << ' ' << ans[m][k] * arr[k][j] << endl;
                ans[i][j] = max(ans[i][j], ans[m][j] * arr[j][k] + ans[m][k] * arr[k][j]);
            }
            //cout << i << ' ' << j  << ' ' << ans[i][j] << endl;
            //cout << endl;
        }
    }
    base Max = 0;
    For(i, 0, n) Max = max(Max, ans[1 << i][i]);
    cout << fixed << Max << endl;
}