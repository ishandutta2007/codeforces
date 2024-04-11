#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

vector<int> prefix_function(string s)
{
    int n = sz(s);
    vector p(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) j = p[j - 1];
        if (s[i] == s[j]) ++j;
        p[i] = j;
    }
    return p;
}

vector<vector<int>> compute_automaton(string s)
{
    s += '#';
    int n = sz(s);
    vector p = prefix_function(s);
    vector aut(n, vector(26, 0));
    for (int i = 0; i < n; ++i)
        for (int c = 0; c < 26; ++c)
        {
            if (i > 0 && 'a' + c != s[i])
                aut[i][c] = aut[p[i - 1]][c];
            else
                aut[i][c] = i + ('a' + c == s[i]);
        }
    return aut;
}

int main()
{ _
    string c, s, t; cin >> c >> s >> t;

    auto saut = compute_automaton(s), taut = compute_automaton(t);

    vector dp(sz(c) + 1, vector(sz(s) + 1, vector(sz(t) + 1, -INF)));
    dp[0][0][0] = 0;

    auto chmax = [](int& x, int y) { return x < y ? x = y, true : false; };

    auto increment = [&](int ks, int kt, int x)
    {
        return (saut[ks][x] == sz(s)) - (taut[kt][x] == sz(t));
    };

    auto next = [&](int i, int ks, int kt, int x) -> int&
    {
        return dp[i + 1][saut[ks][x]][taut[kt][x]];
    };

    for (int i = 0; i < sz(c); ++i)
        for (int ks = 0; ks <= sz(s); ++ks)
            for (int kt = 0; kt <= sz(t); ++kt)
            {
                int cur = dp[i][ks][kt];
                if (cur == -INF) continue;

                if (c[i] == '*')
                    for (int x = 0; x < 26; ++x)
                        chmax(next(i, ks, kt, x), cur + increment(ks, kt, x));
                else
                    chmax(next(i, ks, kt, c[i] - 'a'), cur + increment(ks, kt, c[i] - 'a'));
            }

    int ans = -INF;
    for (int ks = 0; ks <= sz(s); ++ks)
        for (int kt = 0; kt <= sz(t); ++kt)
            ans = max(ans, dp[sz(c)][ks][kt]);

    cout << ans << endl;

    exit(0);
}