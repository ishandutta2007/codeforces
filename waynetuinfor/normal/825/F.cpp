#include <bits/stdc++.h>
using namespace std;

vector<int> kmp(const string &s) {
    vector<int> f(s.size(), 0);
    int k = 0;
    for (int i = 1; i < (int)s.size(); ++i) {
        while (k > 0 && s[i] != s[k]) k = f[k - 1];
        if (s[i] == s[k]) ++k;
        f[i] = k;
    }
    return f;
}

const int maxn = 8000 + 5;
int dp[maxn];

int calc(int x) {
    int res = 0;
    for (; x > 0; ++res, x /= 10);
    return res;
}

void upd(int &x, int y) {
    if (y < x) x = y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    for (int i = 1; i < maxn; ++i) dp[i] = 1e9;
    for (int i = 0; i < (int)s.size(); ++i) {
        string t = s.substr(i, (int)s.size() - i);
        vector<int> f = kmp(t);
        for (int j = 1; i + j <= (int)s.size(); ++j) {
            upd(dp[i + j], dp[i] + j + 1);
            int rec = j - f[j - 1];
            if (j % rec == 0)
                upd(dp[i + j], dp[i] + rec + calc(j / rec));
        }
    }
    cout << dp[(int)s.size()] << endl;
}