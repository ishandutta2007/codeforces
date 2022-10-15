#include "bits/stdc++.h"

using namespace std;

#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

constexpr int amax = 1e9;

bool query_greater(int x)
{
    if (x >= amax) return false;
    cout << "> " << x << endl;
    int res; cin >> res;
    return (bool)res;
}

int query_index(int i)
{
    cout << "? " << i + 1 << endl;
    int res; cin >> res;
    return res;
}

const int FIXED_RANDOM = (int)chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(FIXED_RANDOM);

int main()
{
    int n; cin >> n;

    int xmax = 0;

    for (int j = 29; j >= 0; --j)
    {
        if (query_greater(xmax + (1 << j))) xmax += 1 << j;
    }

    xmax += 1;

    uniform_int_distribution<int> unif(0, n - 1);

    int g = 0;

    for (int j = 0; j < 30; ++j)
    {
        int x = query_index(unif(rng));
        g = gcd(g, xmax - x);
    }

    cout << "! " << (xmax - (n - 1) * g) << " " << g << endl;

    exit(0);
}