#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i], --a[i];
    int ans = 0;
    for (int i = 0; i < n; ) {
        set<int> s;
        s.insert(a[i]);
        s.erase(i);
        ++ans;
        int j = i + 1;
        while (j < n && s.size()) {
            s.insert(a[j]);
            s.erase(j);
            ++j;
        }
        i = j;
    }
    cout << ans << endl;
}