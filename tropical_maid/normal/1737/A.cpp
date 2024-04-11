#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        string S;
        cin >> n >> k >> S;
        int cnt[26] = {};
        for (char c : S) {
            ++cnt[c - 'a'];
        }
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (cnt[j] == 0 || j == n / k) {
                    printf("%c", char(j + 'a'));
                    break;
                }
                --cnt[j];
            }
        }
        printf("\n");
    }
    return 0;
}