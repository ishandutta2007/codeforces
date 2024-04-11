#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<int> ans;
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && a[j] == (j - i + 1)) ++j;
        ans.push_back(j - i);
        i = j;
    } 
    cout << ans.size() << endl;
    for (int x : ans) cout << x << ' '; cout << endl;
}