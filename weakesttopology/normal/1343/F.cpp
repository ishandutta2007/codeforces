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

void solve()
{
    int n;
    cin >> n;

    vector<int> freq(n, 0);

    vector<vector<int>> I(n - 1), V(n);
    for (int i = 0; i < n - 1; ++i)
    {
        auto& v = I[i];
        int k;
        cin >> k;
        v.resize(k);
        for (auto& x : v)
        {
            cin >> x;
            --x;
            freq[x] += 1;
            V[x].push_back(i);
        }
    }

    vector<int> p, s;

    for (int x = 0; x < n; ++x)
    {
        if (freq[x] == 1) s.push_back(x);
    }

    for (auto t : s)
    {
        priority_queue<pair<int, int>> pq;
        vector<int> vis(n, 0), cnt(n, 0), rem(n - 1, 0);

        auto f = freq;
        pq.emplace(0, t);
        while (not empty(pq))
        {
            auto [c, x] = pq.top();
            pq.pop();
            p.push_back(x);
            vis[x] += 1;
            for (auto j : V[x])
            {
                if (not rem[j])
                {
                    rem[j] = 1;
                    for (auto y : I[j])
                    {
                        cnt[y] += 1;
                        if (--f[y] == 1) pq.emplace(cnt[y], y);
                    }
                }
            }
        }
        for (int x = 0; x < n; ++x)
        {
            if (not vis[x]) p.push_back(x);
        }
        reverse(all(p));
        bool good = true;

        for (int r = 1; r < n; ++r)
        {
            bool found = false;
            vector<int> w;
            for (int l = r; l >= 0; --l)
            {
                auto iter = lower_bound(all(w), p[l]);
                w.insert(iter, p[l]);
                if (count(all(I), w))
                {
                    found = true;
                    break;
                }
            }
            if (not found)
            {
                good = false;
                break;
            }
        }
        if (good) break;
    }


    for (int i = 0; i < n; ++i)
    {
        cout << p[i] + 1 << "\n "[i + 1 < n];
    }
}

int main()
{ _
    int t;
    cin >> t;
    while (t--) solve();
    exit(0);
}