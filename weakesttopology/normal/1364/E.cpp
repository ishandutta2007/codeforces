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

constexpr int max_queries = 4269;

int query(int i, int j)
{
    static int num_queries = 0;
    assert(++num_queries <= max_queries);
    cout << "? " << i + 1 << " " << j + 1 << endl;
    int res;
    cin >> res;
    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> V;
    int x = -1, firstmask = -1, y = -1, secondmask = -1;

    uniform_int_distribution<int> unif(0, n - 1);

    while (true)
    {
        int z = unif(rng), w = z;
        while (z == w) w = unif(rng);

        int mask = query(z, w);

        bool good = false;
        for (auto [u, prevmask] : V)
        {
            if ((mask & prevmask) == 0)
            {
                good = true;
                x = (z != u ? z : w), firstmask = mask;
                y = u, secondmask = prevmask;
                break;
            }
        }

        if (good) break;
        else V.emplace_back(z, mask);
    }

    vector<int> p(n, -1);
 
    p[x] = query(x, y) & ~secondmask;
    p[y] = query(x, y) & ~firstmask;

    int z = -1;

    if (p[x] == 0) z = x;
    if (p[y] == 0) z = y;

    vector<int> I(n);
    iota(all(I), 0);
    shuffle(all(I), rng);

    for (auto i : I) if (p[i] == -1)
    {
        if (z == -1)
        {
            p[i] = (query(i, x) & ~firstmask) | (query(i, y) & ~secondmask);
            if (p[i] == 0) z = i;
        }
        else
        {
            p[i] = query(i, z);
        }
    }
 
    cout << "!";
    for (int i = 0; i < n; ++i) cout << " " << p[i];
    cout << endl;

    exit(0);
}