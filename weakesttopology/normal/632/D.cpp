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
    int n, m; cin >> n >> m;

    vector<vector<int>> I(m + 1);

    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        if (x <= m) I[x].push_back(i);
    }

    vector<int> ctdiv(m + 1, 0);

    for (int x = 1; x <= m; ++x)
    {
        int k = size(I[x]);
        if (k == 0) continue;
        for (int y = x; y <= m; y += x) ctdiv[y] += k;
    }

    int l = -1, k = -1;

    for (int x = 1; x <= m; ++x)
    {
        if (ctdiv[x] > k)
        {
            l = x, k = ctdiv[x];
        }
    }

    vector<int> div;

    for (int x = 1; x <= l; ++x) if (l % x == 0 && not empty(I[x]))
    {
        for (auto i : I[x]) div.push_back(i);
    }

    sort(all(div));

    cout << l << " " << k << endl;

    for (int j = 0; j < k; ++j)
        cout << div[j] + 1 << "\n "[j + 1 < k];

    exit(0);
}