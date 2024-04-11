#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    map<int, vector<int>> data;
    for (int i = 0; i < N; ++i) {
        int s, r;
        cin >> s >> r;
        data[s - 1].push_back(r);
    }

    for (auto& p : data) {
        sort(p.second.begin(), p.second.end());
    }

    int total = 0, ans = 0;
    int sum[M];
    fill(sum, sum + M, 0);

    while (!data.empty()) {
        set<int> neg, emp;

        for (auto& p : data) {
            int s = p.first, r = p.second.back();
            p.second.pop_back();

            if (sum[s] + r < 0) {
                neg.insert(p.first);
                continue;
            }
            sum[s] += r;
            total += r;

            if (p.second.empty()) emp.insert(p.first);
        }

        for (int s : neg) {
            total -= sum[s];
            data.erase(s);
        }

        ans = max(ans, total);

        for (int s : emp) {
            total -= sum[s];
            data.erase(s);
        }
    }

    cout << ans << endl;
    return 0;
}