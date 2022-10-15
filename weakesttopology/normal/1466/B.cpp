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

int solve()
{
    int n; cin >> n;

    vector<int> x(n);

    for (int i = 0; i < n; ++i) cin >> x[i];

    x[n - 1] += 1;

    for (int i = n - 2; i >= 0; --i)
    {
        if (x[i] + 1 < x[i + 1]) x[i] += 1;
    }

    sort(all(x));

    return (int)distance(begin(x), unique(all(x)));
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}