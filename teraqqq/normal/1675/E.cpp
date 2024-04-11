#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> used(26, false);
    string ans;

    for (char ch : s) {
        int c = ch - 'a';
        while (k != 0) {
            while (used[c] && c > 0) c--; 
            if (c == 0) break;

            used[c] = true;
            k--;
        }
        while (used[c] && c > 0) c--; 
        ans.push_back(c + 'a');
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while(t--) solve();
}