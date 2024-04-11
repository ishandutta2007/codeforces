#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> a(N + 1);
        for (int i = 1; i <= N; ++i) cin >> a[i];
        if (N == 1){
            cout << 0 << '\n';
            continue;
        }
        int ans = inf;
        for (int i = 1; i <= N; ++i){
            for (int j = i + 1; j <= N; ++j){
                int cur = 0;
                double m = (.0 + a[j] - a[i]) / (j - i);
                double b = -m * i + a[i];
                for (int k = 1; k <= N; ++k){
                    double val = m * k + b;
                    if (abs(val - a[k]) > 1e-9) cur++;
                }
                ans = min(cur, ans);
            }
        }
        cout << ans << '\n';
    }
}