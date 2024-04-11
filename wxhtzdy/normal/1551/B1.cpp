#include <bits/stdc++.h>

using namespace std;

void solve() {
    string S; cin >> S;
    int N = (int) S.size();
    vector<int> cnt(26);
    for (int i = 0; i < N; i++) {
        cnt[S[i] - 'a']++;
    }
    int x = 0, y = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 1) {
            if (x < y) x++;
            else y++;
        } else if (cnt[i] > 1) x++, y++;
    }
    cout << min(x, y) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt; cin >> tt;
    while (tt--)
        solve();
    return 0;
}