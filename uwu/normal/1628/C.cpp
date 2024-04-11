#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1010;
int a[MN][MN], yes[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        // ms(yes, 0);
        for (int i = 1; i <= N; ++i){
            for (int j = 1; j <= N; ++j){
                cin >> a[i][j];
                yes[i][j] = 0;
            }
        }
        for (int n = 2; n <= N; n += 2){
            for (int i = n - 1; i >= 1; i -= 4){
                yes[n][i] = 1;
            }
            for (int i = n - 3; i >= 1; i -= 4){
                yes[i][n] = 1;
            }
        }
        int ans = 0;
        for (int i = 1; i <= N; ++i){
            for (int j = 1; j <= N; ++j){
                if (yes[i][N - j + 1]) yes[i][j] = 1;
                if (yes[i][j]) ans ^= a[i][j];
                // cout << yes[i][j];
            }
            // cout << '\n';
        }
        cout << ans << '\n';
        // for (int i = 1; i <= N; ++i){
        //     for (int j = 1; j <= N; ++j){
        //         int cnt = yes[i - 1][j] + yes[i][j - 1] + yes[i + 1][j] + yes[i][j + 1];
        //         cout << cnt;
        //         // assert(cnt % 2 == 1);
        //     }
        //     cout << '\n';
        // }
    }
}