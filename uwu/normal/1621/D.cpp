#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 501;

ll c[MN][MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        ll tot = 0;
        for (int i = 1; i <= 2 * N; ++i){
            for (int j = 1; j <= 2 * N; ++j){
                cin >> c[i][j];
                if (i > N && j > N) tot += c[i][j];
            }
        }
        cout << tot + min({c[N + 1][N], c[N][N + 1], c[2 * N][N], c[N][N * 2], c[N + 1][1], c[1][N + 1], c[1][2 * N], c[2 * N][1]}) << '\n';
    }
}