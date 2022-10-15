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

    int a = 0;

    for (int i = 0, sum = 0; i < n; ++i)
    {
        int x; cin >> x;
        a = max(a, sum += x);
    }

    int m; cin >> m;

    int b = 0;

    for (int j = 0, sum = 0; j < m; ++j)
    {
        int x; cin >> x;
        b = max(b, sum += x);
    }

    return a + b;
}

int main()
{ _
    int t; cin >> t;
    while (t--) cout << solve() << endl;
    exit(0);
}