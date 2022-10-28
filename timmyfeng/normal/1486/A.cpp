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

        bool ok = true;
        long long sum = 0, low = 0;
        for (int i = 0; i < n; ++i) {
            int h;
            cin >> h;

            sum += h;
            low += i;
            ok &= (sum >= low);
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
}