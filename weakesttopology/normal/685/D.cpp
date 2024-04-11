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

template<typename T>
T intersection(pair<T, T> I, pair<T, T> J)
{
    return max<T>(0, min(I.second, J.second) - max(I.first, J.first) + 1);
}

int main()
{ _
    int n, k;
    cin >> n >> k;

    vector<int> x(n), y(n), values;
    map<int, vector<int>> C, D;

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        C[x[i]].push_back(i);
        D[x[i] + k].push_back(i);
        values.insert(end(values), {x[i], x[i] + k});
    }

    sort(all(values)), values.erase(unique(all(values)), end(values));
    int m = size(values);

    vector<ll> res(n + 1, 0);

    multiset<int> S = {-INF, +INF};

    for (int j = 0; j + 1 < m; ++j) {
        if (C.count(values[j])) {
            const auto& v = C[values[j]];
            for (auto i : v) S.insert(y[i]);
        }
        if (D.count(values[j])) {
            const auto& v = D[values[j]];
            for (auto i : v) S.erase(S.find(y[i]));
        }

        ll delta = values[j + 1] - values[j];

        int cnt = 0;
        for (auto iterl = ++begin(S), iterr = iterl; iterl != prev(end(S)); ++iterl, cnt -= 1) {
            pair<int, int> I(*prev(iterl) + 1, *iterl);
            if (iterl != iterr) res[cnt] += delta * intersection<int>(I, {*prev(iterr) - k + 1, *iterr - k});
            while (*iterr < *iterl + k) {
                cnt += 1;
                res[cnt] += delta * intersection<int>(I, {*iterr - k + 1, *next(iterr) - k});
                ++iterr;
            }
        }
    }

    for (int x = 1; x <= n; ++x) cout << res[x] << "\n "[x < n];

    exit(0);
}