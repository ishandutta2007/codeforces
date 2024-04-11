#include <bits/stdc++.h>
using namespace std;

int cnt[26];

int main() {
    string s; cin >> s;
    int k; cin >> k;
    if (k > (int)s.length()) return cout << "impossible" << endl, 0;
    int has = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (!cnt[s[i] - 'a']) ++has;
        ++cnt[s[i] - 'a'];
    }
    vector<int> vec;
    for (int i = 0; i < 26; ++i) vec.push_back(i);
    sort(vec.begin(), vec.end(), [](const int& a, const int& b) { return cnt[a] > cnt[b]; });
    k -= has;
    int ans = 0, ind = 0;
    while (k > 0) {
        if (cnt[vec[ind]] <= 1) return cout << "impossible" << endl, 0;
        ans += min(k, cnt[vec[ind]] - 1); k -= min(k, cnt[vec[ind]] - 1);
        ++ind;
    }
    cout << ans << endl;
    return 0;
}