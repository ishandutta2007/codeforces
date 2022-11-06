#include <bits/stdc++.h>
using namespace std;

const int maxn = 7e4 + 10;
string s[maxn];
unordered_map<string, int> cnt;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) {
        set<string> st;
        for (int l = 0; l < 9; ++l) {
            for (int r = l; r < 9; ++r) {
                int len = r - l + 1;
                st.insert(s[i].substr(l, len));
            }
        }
        for (auto it = st.begin(); it != st.end(); ++it) cnt[*it]++;
    } 
    for (int i = 0; i < n; ++i) {
        bool ans = false;
        for (int len = 1; len <= 9 && !ans; ++len) {
            for (int j = 0; j < 9 && !ans; ++j) {
                if (j + len > 9) break;
                if (cnt[s[i].substr(j, len)] == 1) {
                    cout << s[i].substr(j, len) << endl;
                    ans = true;
                }
            }
        }
    }
    return 0;
}