#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool work(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
    return (a.second <= b.second && b.second <= c.second)
        or (a.second >= b.second && b.second >= c.second);
}

bool work(int l, int r, vector<pair<int, int> > &a) {
    if (r - l <= 1) return false;
    if (r - l == 2) {
        return work(a[l], a[l + 1], a[l + 2]);
    }
    else {
        return work(a[l], a[l + 1], a[l + 2]) 
                or work(a[l + 1], a[l + 2], a[l + 3])
                or work(a[l], a[l + 2], a[l + 3])
                or work(a[l], a[l + 1], a[l + 3]);
    }

}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<pair<int, int> > b(n);
        for (int i = 0; i < n; i++) {
            b[i] = make_pair(i, a[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= max(i - 3, 0); j--) {
                ans += !work(j, i, b);
            }
        }
        cout << ans << "\n";
    }
}