#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        for (auto& i : a) {
            cin >> i;
        }
        sort(a.begin(), a.end());
        cout << a[n] - a[n - 1] << '\n';
    }
}