#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> l, r;
    int nxt = 0;
    for (int i = 0; i < n; i++) {
        while (a[i] > nxt) {
            nxt++;
            l.push_back(i + 1);
        }
        while (a[i] < nxt) {
            nxt--;
            r.push_back(i);
        }
    }
    while (nxt > 0) {
        nxt--;
        r.push_back(n);
    }
    int j = 0;
    cout << l.size() << '\n';
    while (j < (int) l.size() && j < (int) r.size()) {
        cout << l[j] << " " << r[j] << '\n';
        j++;
    }
    return 0;
}