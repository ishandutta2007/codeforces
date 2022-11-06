#include <bits/stdc++.h>
using namespace std;

int main() {
    int k; cin >> k;
    string n; cin >> n;
    int cnt = 0;
    for (int i = 0; i < n.length(); ++i) {
        cnt += (n[i] - '0');
    }
    vector<pair<int, int>> vec;
    for (int i = 0; i < n.length(); ++i) {
        vec.push_back(make_pair(n[i] - '0', i));
    }
    sort(vec.begin(), vec.end());
    int ans = 0;
    for (auto i : vec) {
        if (cnt >= k) break;
        cnt += 9 - i.first;
        ++ans;
    }
    cout << ans << endl;
}