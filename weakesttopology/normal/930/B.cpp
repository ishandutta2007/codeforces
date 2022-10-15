#include <bits/stdc++.h>
using namespace std;
constexpr int L = 5000, K = 26;
int cnt[K][L][K];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int l = (int)s.size();
    for (int i = 0; i < l; ++i) {
        for (int k = 0; k < l; ++k) {
            ++cnt[s[i] - 'a'][k][s[(i + k) % l] - 'a'];
        }
    }
    double ans = 0;
    for (int x = 0; x < K; ++x) {
        double probletter = 1.0 * count(begin(s), end(s), 'a' + x) / l;
        double probwin = 0;
        for (int k = 0; k < l; ++k) {
            int uniq = 0, tot = 0;
            for (int y = 0; y < K; ++y) {
                uniq += cnt[x][k][y] == 1;
                tot += cnt[x][k][y];
            }
            probwin = max(probwin, 1.0 * uniq / tot);
        }
        ans += probwin * probletter;
    }
    cout << setprecision(10) << fixed;
    cout << ans << '\n';
    exit(0);
}