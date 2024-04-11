#include <bits/stdc++.h>
using namespace std;

void test_case() {
    int n;
    cin >> n;
    int a[n];
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    priority_queue<pair<int, int>> q;
    for (auto c : cnt) {
        q.push({c.second, c.first});
    }
    while ((int) q.size() > 1) {
        n -= 2;
        auto x = q.top();
        q.pop();
        auto y = q.top();
        q.pop();
        if (x.first > 1) {
            q.push({x.first - 1, x.second});
        }
        if (y.first > 1) {
            q.push({y.first - 1, y.second});
        }
    }
    cout << n << '\n';
}

int main() {
    int tt;
    cin >> tt;
    while (tt--)
        test_case();
    return 0;
}