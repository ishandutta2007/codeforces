#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

vector<int> prefix_function(const string& s) {
    int n = (int)size(s);
    vector<int> p(n, 0);
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) ++j;
        p[i] = j;
    }
    return p;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    int n = (int)size(s);

    auto p = prefix_function(s);

    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        dp[p[i]] += 1;
    }
    for (int x = n; x > 0; --x) {
        dp[p[x - 1]] += dp[x];
        dp[x] += 1;
    }

    vector<int> I;
    for (int x = n; x != 0; x = p[x - 1]) I.push_back(x);

    cout << size(I) << endl;
    sort(all(I));
    for (auto x : I) {
        cout << x << " " << dp[x] << endl;
    }

    exit(0);
}