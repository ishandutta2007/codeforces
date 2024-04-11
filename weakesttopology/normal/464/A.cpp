#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int n, p; cin >> n >> p;

    string s; cin >> s;

    auto add = [&p](const string& s, int i, int x)
    {
        x = (x + p) % p;

        char d[3] = { s[i], s[max(i - 1, 0)], s[max(i - 2, 0)] };

        char c = s[i];

        for (int k = 0; k < p && find(all(d), c) != end(d); ++k)
        {
            c = 'a' + (c + x - 'a') % p;
        }

        return c;
    };

    string ans = "NO";

    for (int i = n - 1; i >= 0; --i)
    {
        if (s[i] >= add(s, i, 1)) continue;

        string r = s;

        r[i] = add(r, i, 1);

        for (int j = i + 1; j < n; ++j)
        {
            for (char nxt = add(r, j, -1); nxt < r[j]; r[j] = nxt, nxt = add(r, j, -1));

            if ((j > 0 && r[j] == r[j - 1]) || (j > 1 && r[j] == r[j - 2]))
                r[j] = add(r, j, 1);
        }

        ans = r;

        break;
    }

    cout << ans << endl;

    exit(0);
}