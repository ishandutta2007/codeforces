#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

string query_range(int la, int ra, int lb, int rb)
{
    int ka = ra - la, kb = rb - lb;
    cout << "? " << ka << " " << kb << endl;
    for (int j = 0; j < ka; ++j) cout << 1 + la + j << "\n "[j + 1 < ka];
    for (int j = 0; j < kb; ++j) cout << 1 + lb + j << "\n "[j + 1 < kb];
    cout << flush;
    string res; cin >> res;
    return res;
}

bool cmp(int la, int ra, int lb, int rb)
{
    return query_range(la, ra, lb, rb) == "SECOND";
}

vector<int> get_candidates(int n)
{
    vector<int> candidates;

    int l = 0, r = n;

    while (l + 1 < r)
    {
        int m = l + (r - l) / 2;

        if (m - l < r - m) candidates.push_back(--r);

        if (cmp(l, m, m, r))
            l = m;
        else
            r = m;
    }

    candidates.push_back(l);

    return candidates;
}

int solve()
{
    int n, k; cin >> n >> k;

    auto candidates = get_candidates(n);

    int heaviest = candidates[0];

    for (int i = 1; i < size(candidates); ++i)
    {
        int idx = candidates[i];
        if (cmp(heaviest, heaviest + 1, idx, idx + 1))
            heaviest = idx;
    }

    debug(heaviest);

    if (heaviest > 0 && query_range(0, 1, heaviest, heaviest + 1) != "EQUAL")
    {
        return 0;
    }

    int ans = 1;

    for (int j = 0; j >= 0;)
    {
        if (cmp(ans, ans + (1 << j), ans - (1 << j), ans)) j -= 1;
        else ans += 1 << j, j += 1;
        while (ans + (1 << j) > n) --j;
    }

    return ans;
}

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        int ans = solve();
        cout << "! " << ans + 1 << endl << flush;
    }
    exit(0);
}