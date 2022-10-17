#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n, H, M;
        cin >> n >> H >> M;
        vector<int> have;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            have.push_back(a * 60 + b);
            have.push_back(a * 60 + b + 60 * 24);
        }
        sort(have.begin(), have.end());
        int answer = *lower_bound(have.begin(), have.end(), H * 60 + M) - (H * 60 + M);
        cout << answer / 60 << ' ' << answer % 60 << '\n';
    }
    return 0;
}