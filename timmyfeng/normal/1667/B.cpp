#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &i : a) cin >> i;

    map<long long, long long> prefix_max = {{0, 1}};

    long long sum = 0, answer = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];

        if (a[i] < 0) answer--;
        else if (a[i] > 0) answer++;

        auto it = prefix_max.lower_bound(sum);
        if (it != prefix_max.begin())
            answer = max(answer, (--it)->second + i);

        it = prefix_max.upper_bound(sum);
        if (it == prefix_max.begin() || answer - i > (--it)->second) {
            prefix_max[sum] = answer - i;
            while (true) {
                auto nxt = prefix_max.upper_bound(sum);
                if (nxt == prefix_max.end() || nxt->second > answer - i) break;
                prefix_max.erase(nxt);
            }
        }
    }

    cout << answer << "\n";
}

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();

    vector<array<long long, 3>> prefixes;

}