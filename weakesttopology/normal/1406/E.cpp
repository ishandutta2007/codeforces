#include "bits/stdc++.h"

using namespace std;

#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) X.begin(), X.end()
#define sz(X) (int)X.size()

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

// xz

int queryA(int a)
{
    cout << "A " << a << endl;
    int r; cin >> r;
    return r;
}

int queryB(int a)
{
    cout << "B " << a << endl;
    int r; cin >> r;
    return r;
}

void queryC(int a)
{
    cout << "C " << a << endl;
    exit(0);
}

int main()
{
    int n; cin >> n;
    vector pr(0, 0LL), lp(n + 1, 0LL);

    for (int i = 2; i <= n; ++i)
    {
        if (lp[i] == 0)
            lp[i] = i, pr.push_back(i);

        for (auto p : pr)
        {
            if (p > lp[i] || i * p > n) break;
            lp[i * p] = p;
        }
    }

    vector vis(n + 1, 0);

    int num = n;
    while (not pr.empty())
    {
        int m = sz(pr) / 2;

        for (int k = m; k < sz(pr); ++k)
        {
            queryB(pr[k]);
            for (int x = pr[k]; x <= n; vis[x] = 1, x += pr[k])
                num -= !vis[x];
        }

        if (queryA(1) != num) break;
        else pr.erase(pr.begin() + m, pr.end());
    }

    while (not pr.empty() && queryA(pr.back()) == 0) pr.pop_back();

    ll ans = 1;

    for (auto p : pr)
    {
        if (p * pr.back() > n && p != pr.back()) continue;

        ll x = p;
        while ((x * p) * ans <= n) x *= p;

        while (x > 1)
        {
            int b = queryB(x);
            int a = queryA(x);
            if (b > 0 && a == 1) break;
            x /= p;
        }
        ans *= x;
    }

    queryC(ans);

    exit(0);
}