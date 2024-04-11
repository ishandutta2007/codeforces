#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }

        int low = find(a.begin(), a.end(), 1) - a.begin();
        int high = find(a.begin(), a.end(), n) - a.begin();

        cout << min({max(low, high) + 1, n - min(low, high), n - abs(low - high) + 1}) << "\n";
    }
}