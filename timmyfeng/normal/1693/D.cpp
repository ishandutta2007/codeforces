#include <bits/stdc++.h>
using namespace std;

vector<int> get_3412(vector<int> a) {
    int n = (int) a.size();

    vector<int> mono;
    vector updates(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        while (!mono.empty() && a[mono.back()] > a[i])
            mono.pop_back();
        if (!mono.empty())
            updates[mono.back()].push_back(i);
        mono.push_back(i);
    }

    mono.clear();
    vector queries(n, vector<int>());
    for (int i = n - 1; i >= 0; --i) {
        while (!mono.empty() && a[mono.back()] < a[i])
            mono.pop_back();
        if (!mono.empty())
            queries[mono.back()].push_back(i);
        mono.push_back(i);
    }

    vector<int> result(n, n);
    map<int, int> prefix_min = {{0, n}, {n + 1, -1}};
    for (int i = n - 1; i >= 0; --i) {
        for (auto j : updates[i]) {
            while (true) {
                auto nxt = prefix_min.upper_bound(a[j]);
                if (nxt->second < j) break;
                prefix_min.erase(nxt);
            }

            if ((--prefix_min.lower_bound(a[j]))->second > j) {
                prefix_min[a[j]] = j;
            }
        }

        for (auto j : queries[i]) {
            result[j] = (--prefix_min.lower_bound(a[j]))->second;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> a(n);
    for (auto &i : a) cin >> i;

    vector<int> right_endpoint = get_3412(a);

    reverse(a.begin(), a.end());
    vector<int> left_endpoint = get_3412(a);

    for (int i = 0; i < n; ++i) {
        if (left_endpoint[i] < n) {
            int j = n - 1 - left_endpoint[i];
            right_endpoint[j] = min(right_endpoint[j], n - 1 - i);
        }
    }

    long long answer = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (i + 1 < n)
            right_endpoint[i] = min(right_endpoint[i], right_endpoint[i + 1]);
        answer += right_endpoint[i] - i;
    }

    cout << answer << "\n";
}