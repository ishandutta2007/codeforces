#include <iostream>

using namespace std;

const int sz = 200100;

long long cnt[30][30];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            cnt[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        cnt[s[0] - 'a'][s[1] - 'a']++;
    }
    long long ans = 0;
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            for (int k = 0; k < 26; ++k) {
                if (k != i) {
                    ans += cnt[i][j] * cnt[k][j];
                }
                if (k != j) {
                    ans += cnt[i][j] * cnt[i][k];
                }
            }
        }
    }
    cout << ans / 2 << '\n';

}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}