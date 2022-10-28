#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    mt19937_64 rng(42);

    int n, m; cin >> n >> m;

    vector<pair<int, vector<int>>> genes(n);
    unordered_map<int, long long> element_code;
    unordered_map<long long, int> hash_index;
    int k = 0;

    for (auto &[w, subsets] : genes) {
        vector<int> a(m);
        for (auto &i : a) {
            cin >> i;
            if (!element_code.contains(i))
                element_code[i] = rng();
        }
        cin >> w;

        vector<long long> hash(1 << m);
        subsets.resize(1 << m);
        for (int mask = 0; mask < (1 << m); ++mask) {
            if (mask > 0) {
                int bit = countr_zero((unsigned) mask);
                hash[mask] = hash[mask ^ (1 << bit)] ^ element_code[a[bit]];
            }

            if (!hash_index.contains(hash[mask]))
                hash_index[hash[mask]] = k++;
            subsets[mask] = hash_index[hash[mask]];
        }
    }
    ranges::sort(genes);

    vector<int> weight_values;
    for (auto &[w, subsets] : genes)
        if (weight_values.empty() || weight_values.back() != w)
            weight_values.push_back(w);
    genes.push_back({INT_MAX, {}});    

    vector<int> low(n, 0), high(n, (int) ssize(weight_values));
    while (low != high) {
        vector<pair<int, int>> queries;
        for (int i = 0; i < n; ++i)
            if (low[i] < high[i])
                queries.push_back({(low[i] + high[i]) / 2, i});
        ranges::sort(queries);

        int query_it = 0;
        vector<int> count_supers(k);
        for (auto &[w, subsets] : genes) {
            while (query_it < ssize(queries) && weight_values[queries[query_it].first] < w) {
                auto [mid, i] = queries[query_it++];

                int count_matches = 0;
                for (int mask = 0; mask < (1 << m); ++mask) {
                    if (popcount((unsigned) mask) % 2 == 0)
                        count_matches += count_supers[genes[i].second[mask]];
                    else
                        count_matches -= count_supers[genes[i].second[mask]];
                }

                if (count_matches > 0)
                    high[i] = mid;
                else
                    low[i] = mid + 1;
            }

            for (auto hash : subsets)
                ++count_supers[hash];
        }
    }

    int ans = INT_MAX;
    for (int i = 0; i < n; ++i) {
        if (low[i] < ssize(weight_values))
            ans = min(ans, genes[i].first + weight_values[low[i]]);
    }

    cout << (ans == INT_MAX ? -1 : ans) << "\n";
}