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
    constexpr int K = 6, M = 1 << K;
    array<int, K> ctchar{};
    array<int, M> ctmask{};

    string s; cin >> s;
    int n = size(s);

    for (auto c : s) ctchar[c - 'a'] += 1;

    vector<bitset<K>> mask(n, bitset<K>().set());

    int m; cin >> m;

    ctmask[M - 1] = n - m;

    for (int j = 0; j < m; ++j)
    {
        int pos; cin >> pos; --pos;

        string t; cin >> t;

        mask[pos] = 0;
        for (auto c : t) mask[pos][c - 'a'] = 1;

        ctmask[mask[pos].to_ulong()] += 1;
    }

    auto check = [&]()
    {
        for (int mask = 1; mask < M; ++mask)
        {
            int neighborhood = 0;
            for (int neighbor = 1; neighbor < M; ++neighbor)
            {
                if (mask & neighbor) neighborhood += ctmask[neighbor];
            }
            int sz = 0;
            for (int x = 0; x < K; ++x)
            {
                if (mask >> x & 1) sz += ctchar[x];
            }
            if (neighborhood < sz) return false;
        }
        return true;
    };

    if (not check())
    {
        cout << "Impossible" << endl;
        exit(0);
    }

    for (int i = 0; i < n; ++i)
    {
        ctmask[mask[i].to_ulong()] -= 1;
        for (int x = 0; x < K; ++x) if (mask[i][x] && ctchar[x] > 0)
        {
            ctchar[x] -= 1;
            if (check())
            {
                s[i] = char('a' + x);
                break;
            }
            ctchar[x] += 1;
        }
    }

    cout << s << endl;

    exit(0);
}