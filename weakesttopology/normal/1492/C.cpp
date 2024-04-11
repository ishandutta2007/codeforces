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
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    vector<int> prefix(m), suffix(m);

    for (int i = 0, j = 0; i < n && j < m; ++i)
    {
        if (s[i] == t[j]) prefix[j++] = i;
    }
    for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; --i)
    {
        if (s[i] == t[j]) suffix[j--] = i;
    }

    int res = 0;

    for (int j = 0; j + 1 < m; ++j)
        res = max(res, suffix[j + 1] - prefix[j]);

    cout << res << endl;

    exit(0);
}