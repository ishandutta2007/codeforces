#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) (X).begin(), (X).end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

string combine(string a, string b)
{
    if (sz(b) < 10) return a + b;

    string res = a + b;

    if (b[sz(b) - 3] == '.') return res.substr(0, 5) + res.substr(sz(res) - 5, 5);
    else
    {
        return res.substr(0, 5) + string(3, '.') + b.substr(sz(b) - 2, 2);
    }
}

int main()
{ _
    string s; cin >> s;
    int n = sz(s);

    if (n == 1)
    {
        cout << "1 " <<  s << endl;
        exit(0);
    }

    vector<string> dp(n, "");
    vector<int> len(n, 0);
    vector<char> last(n, '*');

    dp[n - 1] = s.substr(n - 1, 1);
    dp[n - 2] = (s[n - 2] == s[n - 1]) ? "" : s.substr(n - 2, 2);

    len[n - 1] = 1;
    len[n - 2] = sz(dp[n - 2]);

    last[n - 1] = 'a' - 1;
    last[n - 2] = len[n - 2] ? s[n - 1] : 'a' - 1;

    auto check = [&](int i)
    {
        if (s[i] != s[i + 1]) return false;
        if (dp[i + 2].empty()) return true;
        if (s[i] > dp[i + 2][0]) return true;
        if (s[i] == dp[i + 2][0] && s[i] > last[i + 2]) return true;
        return false;
    };

    for (int i = n - 3; i >= 0; --i)
    {
        if (check(i))
        {
            dp[i] = dp[i + 2];
            len[i] = len[i + 2];
            last[i] = last[i + 2];
        }
        else
        {
            dp[i] = combine(string(1, s[i]), dp[i + 1]);
            len[i] = 1 + len[i + 1];
            last[i] = (s[i] == dp[i + 1][0]) ? last[i + 1] : dp[i + 1][0];
        }
    }

    for (int i = 0; i < n; ++i)
        cout << len[i] << " " << dp[i] << endl;

    exit(0);
}