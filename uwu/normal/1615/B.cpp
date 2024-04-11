#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int psa[MN][30];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    for (int i = 1; i < MN; ++i){
        for (int j = 0; j < 30; ++j){
            if (!(1 & (i >> j))) psa[i][j]++;
            psa[i][j] += psa[i - 1][j];
        }
    }
    while (T--){
        int l, r; cin >> l >> r;
        int ans = inf;
        for (int j = 0; j < 30; ++j){
            ans = min(ans, psa[r][j] - psa[l - 1][j]);
        }
        cout << ans << '\n';
    }
}