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
    int n; cin >> n;

    vector a(n, 0);

    for (int i = 0; i < n; ++i) cin >> a[i];

    function<int(int, int, int)> solve = [&](int l, int r, int h)
    {
        if (r - l <= 1) return 0;

        auto pred = [&h](int x){ return x >> h & 1 ? true : false; };
        auto iter = partition(begin(a) + l, begin(a) + r + 1, pred);

        int mid = distance(begin(a), iter);

        int leftcost = solve(l, mid - 1, h - 1), rightcost = solve(mid, r, h - 1);

        return min(leftcost + max(0, r - mid), max(0, mid - 1 - l) + rightcost);
    };

    int ans = solve(0, n - 1, 29);

    cout << ans << endl;

    exit(0);
}