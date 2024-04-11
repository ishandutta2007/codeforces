#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int solve()
{
    int n; cin >> n;
    string s; cin >> s;

    auto solve = [&](char c)
    {
        bool good = true;
        for (int i = 0; i < n; ++i)
            if (s[i] != c && s[i] != '-') good = false;
        return good;
    };

    if (solve('<') || solve('>')) return n;

    int ans = 0;

    for (int i = 0; i < n; ++i)
        if (s[i] == '-' || s[(i + 1) % n] == '-') ++ans;

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}