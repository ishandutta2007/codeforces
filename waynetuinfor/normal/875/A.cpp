#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> ans;
    for (int i = 0; i <= 100; ++i) {
        int k = n - i;
        int p = 0;
        while (k) {
            p += k % 10; k /= 10;
        }
        if (p == i) ans.push_back(n - i);
    } 
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i : ans) cout << i << endl;
    return 0;
}