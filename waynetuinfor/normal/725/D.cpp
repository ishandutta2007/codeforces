#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
multiset<int64_t> ms;
pair<int64_t, int64_t> p;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    cin >> p.first >> p.second;
    vector<pair<int64_t, int64_t>> vec;
    for (int i = 0; i < n - 1; ++i) {
        int64_t a, b; cin >> a >> b;
        if (a > p.first) ms.insert(b - a + 1);
        else vec.push_back(make_pair(a, b));
    }
    sort(vec.begin(), vec.end()); reverse(vec.begin(), vec.end());
    int rk = (int)ms.size() + 1;
    if (rk == 1) return cout << rk << endl, 0;
    int ind = 0;
    while (p.first > 0 && ms.size()) {
        auto it = ms.begin();
        if (p.first < *it) break;
        p.first -= *it; ms.erase(ms.find(*it));
        while (ind < vec.size() && vec[ind].first > p.first) ms.insert(vec[ind].second - vec[ind].first + 1), ++ind;
        rk = min(rk, (int)ms.size() + 1);
    }
    cout << rk << endl;
    return 0;
}