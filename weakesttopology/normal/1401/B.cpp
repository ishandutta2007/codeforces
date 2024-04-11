#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

int c(int a, int b)
{
    if (a > b) return a * b;
    if (a == b) return 0;
    return - a * b;
}

int solve(vector<int>& x, vector<int>& y)
{
    if (x[0] == 0 && x[1] == 0 && x[2] == 0) return 0;

    int res = -INF;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            int d = min(x[i], y[j]);
            if (d == 0) continue;
            x[i] -= d, y[j] -= d;
            res = max(res, d * c(i, j) + solve(x, y));
            x[i] += d, y[j] += d;
        }

    return res;
}

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        vector x(3, 0), y(3, 0);
        for (int i = 0; i < 3; ++i) cin >> x[i];
        for (int i = 0; i < 3; ++i) cin >> y[i];
        cout << solve(x, y) << endl;
    }
    exit(0);
}