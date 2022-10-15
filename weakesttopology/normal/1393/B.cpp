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

int main()
{ _
    int n; cin >> n;

    int N = 1 << 18;

    set<int> S2, S4, S6, S8;

    vi a(N, 0);
    for (int i = 0; i < n; ++i)
    {
        int x; cin >> x;
        a[x]++;
        if (a[x] == 2)
            S2.insert(x);
        else if (a[x] == 4)
        {
            S2.erase(x);
            S4.insert(x);
        }
        else if (a[x] == 6)
        {
            S4.erase(x);
            S6.insert(x);
        }
        else if (a[x] == 8)
        {
            S6.erase(x);
            S8.insert(x);
        }
    }

    auto check = [&]()
    {
        if (sz(S8) >= 1)
            return true;
        if (max(sz(S4), sz(S6)) >= 2)
            return true;
        if (sz(S6) >= 1 && max(sz(S2), sz(S4)) >= 1)
            return true;
        if (sz(S4) >= 1 && sz(S2) >= 2)
            return true;
        return false;
    };

    int q; cin >> q;
    for (int z = 0; z < q; ++z)
    {
        char c; cin >> c;
        int x; cin >> x;
        if (c == '-')
        {
            if (a[x] == 2)
                S2.erase(x);
            if (a[x] == 4)
            {
                S4.erase(x);
                S2.insert(x);
            }
            if (a[x] == 6)
            {
                S6.erase(x);
                S4.insert(x);
            }
            if (a[x] == 8)
            {
                S8.erase(x);
                S6.insert(x);
            }
        }
        a[x] += c == '+' ? 1 : -1;
        if (c == '+')
        {
            if (a[x] == 2)
                S2.insert(x);
            else if (a[x] == 4)
            {
                S2.erase(x);
                S4.insert(x);
            }
            else if (a[x] == 6)
            {
                S4.erase(x);
                S6.insert(x);
            }
            else if (a[x] == 8)
            {
                S6.erase(x);
                S8.insert(x);
            }
        }
        string ans = check() ? "YES" : "NO";
        cout << ans << endl;
    }

    exit(0);
}