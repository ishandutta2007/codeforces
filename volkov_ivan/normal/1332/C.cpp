#include <iostream>
#include <cstring>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt[256];
    int res = 0;
    for (int i = 0; i <= k - i - 1; i++) {
        memset(cnt, 0, sizeof(cnt));
        int all = 0, maxi = 0;
        for (int j = i; j < n; j += k) {
            maxi = max(maxi, ++cnt[s[j]]);
            all++;
        }
        if (i != k - i - 1) {
            for (int j = k - i - 1; j < n; j += k) {
                maxi = max(maxi, ++cnt[s[j]]);
                all++;
            }
        }
        res += all - maxi;
    }
    cout << res << "\n";
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
    return 0;
}