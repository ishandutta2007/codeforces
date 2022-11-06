#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnt = 0, g = 0;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            if (g < k / 2) ++cnt, ++g, ans.push_back(i);
        } else {
            if (cnt) --cnt, ans.push_back(i);
        }
    }
    assert(ans.size() == k);
    for (int i = 0; i < ans.size(); ++i) cout << s[ans[i]];
    cout << endl;
}