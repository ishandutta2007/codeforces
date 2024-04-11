#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            --a[i];
        }
        sort(a.begin(), a.end());
        int j = 0, t = k + 1;
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; i++) {
            cnt[(int) (s[i] - 'a')] += t;
            while (j < k && a[j] == i) {
                j++;
                t--;
            }
        }
        for (int i = 0; i < 26; i++) {
            cout << cnt[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}