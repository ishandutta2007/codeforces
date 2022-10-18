#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()) << '\n';
    }
    return 0;
}