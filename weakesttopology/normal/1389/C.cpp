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
#define read(x) for (int xx = 0; xx < sz(x); ++xx) cin >> x[xx];

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;

using vi = vector<int>;
using vll = vector<ll>;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

struct Counter
{
    int c[10] = { 0 };
    Counter operator+(const Counter& rhs)
    {
        Counter r = *this;
        for (int i = 0; i < 10; ++i)
            r.c[i] += rhs.c[i];
        return r;
    }
    Counter operator-(const Counter& rhs)
    {
        Counter r = *this;
        for (int i = 0; i < 10; ++i)
            r.c[i] -= rhs.c[i];
        return r;
    }
    Counter operator!()
    {
        Counter r = *this;
        for (int i = 0; i < 10; ++i)
            r.c[i] = !r.c[i];
        return r;
    }
};

int main()
{ _
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        int n = sz(s);
        vector<Counter> a(n);
        vector<vector<int>> pos(10, vi());
        for (int i = 0; i < n; ++i)
        {
            a[i].c[s[i] - '0'] = 1;
            pos[s[i] - '0'].push_back(i);
        }
        for (int i = 1; i < n; ++i)
            a[i] = a[i - 1] + a[i];
        auto sum = [&a](int i, int j)
        {
            if (i > j) return Counter();
            return i > 0 ? a[j] - a[i] : a[j];
        };

        int ans = 2;
        for (int d = 0; d < 10; ++d)
        {
            if (sz(pos[d]) <= 1)
                continue;

            Counter x;
            for (int i = 1; i < sz(pos[d]); ++i)
                x = x + !!sum(pos[d][i - 1], pos[d][i]);
            x = x + !!sum(pos[d].back(), n - 1);
            for (int l = 0; l < 10; ++l)
                if (l != d) ans = max(ans, 2 * x.c[l]);
        }
        for (int d = 0; d < 10; ++d)
            ans = max(ans, sum(0, n - 1).c[d]);
        ans = n - ans;
        cout << ans << endl;
    }
    exit(0);
}