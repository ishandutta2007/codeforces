#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    multiset<int> s;
    for (int i = 0; i < n; ++i) s.insert(a[i]);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        auto it = s.upper_bound(a[i]);
        if (it != s.end()) {
            int x = *it;
            ++ans;
            s.erase(s.find(x));
        } else {
            int x = *s.begin();
            s.erase(s.find(x));
        }
    }
    printf("%d\n", ans);
    return 0;
}