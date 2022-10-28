#include <bits/stdc++.h>
using namespace std;

long long get_sum(vector<int> a) {
    int n = (int) a.size();
    sort(a.begin(), a.end());
    long long answer = 0;
    for (int i = 0; i < n; ++i) {
        answer += (long long) (i - (n - 1 - i)) * a[i];
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;

    map<int, vector<int>> rows, cols;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int c; cin >> c;
            rows[c].push_back(i);
            cols[c].push_back(j);
        }
    }

    long long answer = 0;

    for (auto &i : rows)
        answer += get_sum(i.second);

    for (auto &i : cols)
        answer += get_sum(i.second);
    
    cout << answer << "\n";
}