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

int main()
{ _
    int n;
    cin >> n;

    vector<int> a(1 << n);
    for (auto& x : a) cin >> x;

    auto values = a;
    sort(all(values)), values.erase(unique(all(values)), end(values));

    for (auto& x : a)
    {
        auto iter = lower_bound(all(values), x);
        x = (int)distance(begin(values), iter);
    }

    int q;
    cin >> q;

    vector<int> queries(q);
    for (auto& e : queries) cin >> e;

    vector<ll> inv(n, 0), comp(n, 0);
    vector<int> aux(1 << n), cnt(1 << n, 0);

    for (int k = 0; k < n; ++k)
    {
        for (int x = 0; x < (1 << n); x += 1 << (k + 1))
        {
            int i = x, istop = i + (1 << k);
            int j = istop, jstop = j + (1 << k);
            int z = x;

            ll cur = 0;

            while (i < istop && j < jstop)
            {
                if (a[i] <= a[j]) aux[z++] = a[i++];
                else
                {
                    cur += istop - i;
                    aux[z++] = a[j++];
                }
            }
            while (i < istop) aux[z++] = a[i++];
            while (j < jstop) aux[z++] = a[j++];

            inv[k] += cur;

            ll rev = (1LL << k) * (1LL << k) - cur;
            for (int i = x; i < x + (1 << k); ++i)
            {
                cnt[a[i]] += 1;
                a[i] = aux[i];
            }
            for (int i = x + (1 << k); i < x + (1 << (k + 1)); ++i)
            {
                rev -= cnt[a[i]];
                a[i] = aux[i];
            }
            for (int i = x; i < x + (1 << (k + 1)); ++i) cnt[a[i]] = 0;

            comp[k] += rev;
        }
    }

    assert(is_sorted(all(a)));

    for (auto e : queries)
    {
        ll res = 0;
        for (int k = 0; k < e; ++k)
        {
            swap(inv[k], comp[k]);
            res += inv[k];
        }
        for (int k = e; k < n; ++k) res += inv[k];
        cout << res << endl;
    }

    exit(0);
}