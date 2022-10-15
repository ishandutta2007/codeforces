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

ll gcd(ll a, ll b, ll& x, ll& y)
{
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main()
{ _
    int n; cin >> n;
    vector a(n, 0LL);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (n == 1)
    {
        cout << "1 1\n0\n1 1\n0\n1 1\n";
        cout << -a[0] << endl;
        exit(0);
    }

    vector b(2, vector(n, 0LL));
    for (int i = 0; i < n; ++i)
    {
        gcd(n - 1, n, b[0][i], b[1][i]);
        b[0][i] *= - a[i], b[1][i] *= - a[i];
    }

    cout << "1 " << n - 1 << endl;
    for (int i = 0; i < n - 1; ++i)
        cout << b[0][i] * (n - 1) << " ";
    cout << endl;

    cout << "1 " << n << endl;
    for (int i = 0; i < n; ++i)
        cout << b[1][i] * n << " ";
    cout << endl;

    a[n - 1] += n * b[1][n - 1];

    cout << n << " " << n << endl;
    cout << -a[n - 1] << endl;

    exit(0);
}