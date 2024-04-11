#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> even, odd;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        (a % 2 == 0 ? even : odd).push_back(a);
    }

    if (even.size() > odd.size()) {
        swap(even, odd);
    }

    sort(odd.begin(), odd.end());

    int ans = 0;
    for (int i = 0; i + even.size() + 1 < odd.size(); ++i) {
        ans += odd[i];
    }

    cout << ans << "\n";
}