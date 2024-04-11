#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N, V;
    cin >> N >> V;

    vector<pair<int, int>> cap[2];
    for (int i = 1; i <= N; ++i) {
        int t, c;
        cin >> t >> c;
        cap[t - 1].push_back(make_pair(c, i));
    }

    vector<int> sum[2];
    for (int i = 0; i < 2; ++i) {
        sort(cap[i].rbegin(), cap[i].rend());
        sum[i].push_back(0);
        for (auto p : cap[i]) {
            sum[i].push_back(sum[i].back() + p.first);
        }
    }

    pair<int, int> pat;
    int total = -1;
    for (int two = 0; two <= cap[1].size(); ++two) {
        int one = min((int)cap[0].size(), V - two * 2);
        if (one < 0) break;

        if (total < sum[0][one] + sum[1][two]) {
            total = sum[0][one] + sum[1][two];
            pat = make_pair(one, two);
        }
    }

    cout << total << endl;
    for (int i = 0; i < pat.first; ++i) {
        cout << cap[0][i].second << endl;
    }
    for (int i = 0; i < pat.second; ++i) {
        cout << cap[1][i].second << endl;
    }
    return 0;
}