#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 301 * 301;

int a[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        vector<pair<int, int>> vec;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                int a; cin >> a;
                vec.push_back({a, (i - 1) * m + j - 1});
            }
        }
        sort(vec.begin(), vec.end());
        ll ans = 0;
        for (int i = 1; i <= n; ++i){
            int s = (i - 1) * m;
            for (int j = 0; j < m; ++j){
                for (int k = j + 1; k < m; ++k){
                    if (vec[s + j].first < vec[s + k].first && vec[s + j].second < vec[s + k].second) ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}