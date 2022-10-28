#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, x; cin >> n >> x;
        int min_a = INT_MAX, max_a = INT_MIN, answer = 0;
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            if (max(max_a, a) - min(min_a, a) > 2 * x) {
                ++answer;
                min_a = max_a = a;
            } else {
                min_a = min(min_a, a);
                max_a = max(max_a, a);
            }
        }
        cout << answer << "\n";
    }
}