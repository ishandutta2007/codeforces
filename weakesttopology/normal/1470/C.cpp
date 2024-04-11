#include "bits/stdc++.h"

using namespace std;

#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

const int FIXED_RANDOM = (int)chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(FIXED_RANDOM);

ll query(int i)
{
    cout << "? " << i + 1 << endl;
    ll res; cin >> res;
    return res;
}

int main()
{
    int n, k; cin >> n >> k;

    query(0);

    uniform_int_distribution<int> unif(0, n - 1);

    int p = -1;

    while (true)
    {
        p = unif(rng);
        if (query(p) < k) break;
    }

    int logn = __builtin_clz(1) - __builtin_clz(n) - 1;

    for (int x = logn; x >= 0; --x)
    {
        int q = (p + (1 << x)) % n;
        if (query(q) < k) p = q;
    }

    for (int it = 0; it < 10; ++it)
    {
        int right = (p + 1) % n;
        if (query(right) < k) p = right;
    }

    int ans = (p + 1) % n + 1;

    cout << "! " << ans << endl;

    exit(0);
}