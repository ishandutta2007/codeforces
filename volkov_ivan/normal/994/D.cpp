#include <iostream>
#include <cassert>
#include <set>

using namespace std;

int ok(pair <int, int> a, pair <int, int> b) {
    if (a.first == b.first && a.second != b.second) return a.first;
    if (a.first == b.second && a.second != b.first) return a.first;
    if (a.second == b.first && a.first != b.second) return a.second;
    if (a.second == b.second && a.first != b.first) return a.second;
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    pair <int, int> a[n], b[m];
    bool poss1[n], poss2[m];
    for (int i = 0; i < n; i++) {
        poss1[i] = 0;
        cin >> a[i].first >> a[i].second;
        if (a[i].second < a[i].first) swap(a[i].first, a[i].second);
    }
    for (int i = 0; i < m; i++) {
        poss2[i] = 0;
        cin >> b[i].first >> b[i].second;
        if (b[i].second < b[i].first) swap(b[i].first, b[i].second);
    }
    set <int> cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ok(a[i], b[j]) != 0) {
                cnt.insert(ok(a[i], b[j]));
                poss1[i] = 1;
                poss2[j] = 1;
            }
        }
    }
    assert(!cnt.empty());
    if (cnt.size() == 1) {
        cout << (*cnt.begin()) << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (!poss1[i]) continue;
        cnt.clear();
        for (int j = 0; j < m; j++) {
            if (ok(a[i], b[j]) != 0) {
                cnt.insert(ok(a[i], b[j]));
            }
        }
        if (cnt.size() == 2) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int j = 0; j < m; j++) {
        if (!poss2[j]) continue;
        cnt.clear();
        for (int i = 0; i < n; i++) {
            if (ok(a[i], b[j]) != 0) {
                cnt.insert(ok(a[i], b[j]));
            }
        }
        if (cnt.size() == 2) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
    return 0;
}