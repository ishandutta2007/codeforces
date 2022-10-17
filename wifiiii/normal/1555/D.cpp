#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<vector<int>> a;
    string base = "abc";
    do {
        string t = base;
        while(t.size() < s.size()) t += base;
        vector<int> tmp(n);
        for(int i = 0; i < n; ++i) tmp[i] = s[i] != t[i];
        for(int i = 1; i < n; ++i) tmp[i] += tmp[i-1];
        a.push_back(tmp);
    } while(next_permutation(base.begin(), base.end()));
    while(q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        int ans = n;
        for(auto &p : a) {
            ans = min(ans, p[r] - (l?p[l-1]:0));
        }
        cout << ans << '\n';
    }
}