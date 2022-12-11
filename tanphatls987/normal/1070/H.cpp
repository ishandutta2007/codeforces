#include <bits/stdc++.h>

using namespace std;

int n;
string s[10004];
map <long long, int> cnt;
map <long long, int> id;

long long val(string s) {
    long long ret = 0;
    for (int i = 0; i < s.size(); ++i) ret = ret * 128 + s[i];
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i];
        set <long long> ss;
        for (int j = 0; j < s[i].size(); ++j) for (int k = 1; k + j - 1 < s[i].size(); ++k) {
            long long gg = val(s[i].substr(j, k));
            ss.insert(gg);
        }
        for (auto x: ss) ++cnt[x], id[x] = i;
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; ++i) {
        string t; cin >> t;
        long long gg = val(t);
        cout << cnt[gg] << ' ' << (id.find(gg) == id.end() ? "-" : s[id[gg]]) << '\n';
    }
    return 0;
}