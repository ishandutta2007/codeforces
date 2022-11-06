#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;

bool vowel(char c) {
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    vector<int> a;
    for (int i = 0; i < s.length(); ++i) a.push_back((int)vowel(s[i]));
    int cnt = accumulate(a.begin(), a.end(), 0);
    double ans = 0.0;
    long long ls = 0, rs = 0;
    int l = 0, r = s.length() - 1, lcnt = 0, rcnt = 0;
    for (int len = 1; len <= s.length(); ++len) {
        long long c = 1ll * len * (cnt - lcnt - rcnt) + rs + ls;
        ans += (double)c / (double)len;
        if (a[l] == 1) ++lcnt, ls += l + 1; 
        if (a[r] == 1) ++rcnt, rs += s.length() - r;
        ++l, --r;
    }
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}