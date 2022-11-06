#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10, inf = 1e9 + 1;
bool v[maxn];

long long ran() {
    return (long long)rand() * (long long)rand();
}

int main() {
    srand(7122);
    int n, st, x; cin >> n >> st >> x;
    if (n <= 1999) {
        int pv = -1, cur = st;
        for (int i = 0; i < n; ++i) {
            cout << "? " << cur << endl;
            int val, nxt; cin >> val >> nxt;
            if (val >= x && pv < x) return cout << "! " << val << endl, 0;
            cur = nxt;
            pv = val;
        }
        cout << "! " << -1 << endl;
        return 0;
    }
    cout << "? " << st << endl;
    v[st] = true;
    int val, nxt; cin >> val >> nxt;
    vector<pair<int, int>> vec;
    vec.push_back(make_pair(val, st));
    if (val >= x) return cout << "! " << val << endl, 0;
    for (int i = 0; i < 1000; ++i) {
        int rnd = ran() % n + 1;
        while (v[rnd]) rnd = ran() % n + 1;
        v[rnd] = true;
        cout << "? " << rnd << endl;
        int val, nxt; cin >> val >> nxt;
        vec.push_back(make_pair(val, rnd));
    }
    sort(vec.begin(), vec.end());
    auto it = lower_bound(vec.begin(), vec.end(), make_pair(x, -1));
    if (it == vec.begin()) return cout << "! " << it->first << endl, 0;
    --it;
    int cur = it->second;
    while (true) {
        if (cur == -1) return cout << "! " << -1 << endl, 0;
        cout << "? " << cur << endl;
        int val, nxt; cin >> val >> nxt;
        if (val >= x) return cout << "! " << val << endl, 0;
        cur = nxt;
    }
    cout << "! " << -1 << endl;
    return 0;
}