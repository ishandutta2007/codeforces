#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);//cin.tie(0);
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

const int amax = 1e9;

uniform_int_distribution<int> unif(1, amax);

// true if x mod a < y mod a

bool modcmp(int x, int y)
{
    cout << "? " << x << " " << y << endl;

    char res; cin >> res;

    if (res == 'e') exit(0);

    return res == 'y';
}

bool checkmlt(int x) { return not modcmp(0, x); }

int solve()
{
    if (checkmlt(1)) return 1;

    int L = 1, R = amax + unif(rng), ct = 0;

    // while (abs(R - L) <= 1e6 || not modcmp(R, L))
    //     tie(L, R) = minmax({ unif(rng), unif(rng) }), ct += 1;

    debug(ct);

    while (L + 1 < R)
    {
        int M = L + (R - L) / 2;

        if (modcmp(M, L))
            R = M;
        else
            L = M;
    }

    vector<pair<int, int>> f;

    for (int x = 2, asup = L + 1; true; ++x)
    {
        if (x * x > asup)
        {
            if (asup > 1) f.emplace_back(asup, 1);
            break;
        }
        int e = 0;
        while (asup % x == 0) asup /= x, e += 1;
        if (e) f.emplace_back(x, e);
    }

    int res = L + 1;

    debug(res);

    vector fpow(35, 1);

    for (auto [x, e] : f)
    {
        for (int i = 1; i <= e; ++i)
            fpow[i] = fpow[i - 1] * x;

        int take = 0;

        for (int i = 10; i >= 0; --i)
            if (take + (1 << i) <= e && checkmlt(res / fpow[take + (1 << i)]))
                take += 1 << i;

        res /= fpow[take];
    }

    debug(res);

    return res;
}

int main()
{ _
    for (string game; cin >> game && game == "start";)
    {
        int ans = solve();
        cout << "! " << ans << endl;
    }

    exit(0);
}