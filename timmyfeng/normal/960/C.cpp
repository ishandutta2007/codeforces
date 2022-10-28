#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, d;
    cin >> x >> d;

    vector<long long> ans;

    long long a = 1;
    while (x > 0) {
        int y = 1;
        while (2 * y - 1 <= x) {
            ans.push_back(a);
            y *= 2;
        }
        x -= y - 1;
        a += d;
    }

    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << "\n";
}