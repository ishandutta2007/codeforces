#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

auto sieve(int N)
{
    vector<int> lp(N + 1, 0), pr;
    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0) pr.push_back(lp[i] = i);
        for (auto p : pr)
        {
            if (p > lp[i] || i * p > N) break;
            lp[i * p] = p;
        }
    }
    return pair(lp, pr);
}

int main()
{ _
    const int N = 1e5 - 1;
    auto [lp, pr] = sieve(N);

    vector isprime(N, 0);

    for (auto p : pr) isprime[p] = 1;

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;

        vector a(n, vector(n, 0));

        for (int i = 1, idx = 10; i < n; ++i)
        {
            a[i][0] = a[0][i] = 1;
            a[i][i] = pr[idx++] - 1;
        }

        while (isprime[pr.back() - (n - 1)]) pr.pop_back();
        a[0][0] = pr.back() - (n - 1);

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
    exit(0);
}