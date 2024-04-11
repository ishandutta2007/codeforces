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

ll sq(ll x) { return x * x; }

int main()
{ _
    ll pt[8][3];

    for (int t = 0; t < 8; ++t)
    {
        for (int i = 0; i < 3; ++i)
            cin >> pt[t][i];
        sort(all(pt[t]));
    }

    auto dist = [&](int s, int t)
    {
        ll d = 0LL;
        for (int i = 0; i < 3; ++i) d += sq(pt[s][i] - pt[t][i]);
        return d;
    };

    int V[8]; iota(all(V), 0);

    auto cmp = [&](int s, int t){ return dist(V[0], s) < dist(V[0], t); };

    auto check = [&]
    {
        for (int t = 0; t < 8; ++t)
            for (int s = t + 1; s < 8; ++s)
                if (equal(all(pt[t]), all(pt[s])))
                    return false;

        sort(1 + all(V), cmp);

        const ll L = dist(V[0], V[1]);

        for (int t = 3; t < 8; ++t)
        {
            if (dist(V[t], V[1]) != dist(V[t], V[2])) continue;
            if (dist(V[t], V[1]) != L) continue;
            swap(V[t], V[3]);
            break;
        }

        swap(V[2], V[3]);

        for (int t = 4; t < 8; ++t)
        {
            for (int s = t; s < 8; ++s)
            {
                if (dist(V[t - 4], V[s]) == L)
                {
                    swap(V[s], V[t]);
                    break;
                }
            }
        }

        for (int t = 0; t < 4; ++t)
        {
            if (dist(V[t], V[(t + 1) % 4]) != L) return false;
            if (dist(V[4 + t], V[4 + (t + 1) % 4]) != L) return false;
            if (dist(V[t], V[4 + t]) != L) return false;
        }

        return true;
    };

    function<bool(int)> backtrack = [&](int t)
    {
        if (t == 8) return check();

        do
        {
            if (backtrack(t + 1)) return true;
        } while(next_permutation(all(pt[t])));

        return false;
    };

    backtrack(0);

    if (check())
    {
        cout << "YES" << endl;
        for (int t = 0; t < 8; ++t)
            for (int i = 0; i < 3; ++i)
                cout << pt[t][i] << "\n "[i < 2];
    }
    else
        cout << "NO" << endl;

    exit(0);
}