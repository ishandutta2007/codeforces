#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
		cout << ([&](){
			int n; cin >> n;

			vector<int> a(n);
			for (auto &i : a) {
				cin >> i;
				while (i % 2 == 0) {
					i /= 2;
				}
			}
			sort(a.rbegin(), a.rend());

			priority_queue<int> b;
			for (int i = 0; i < n; ++i) {
				int x; cin >> x;
				b.push(x);
			}

			for (int i = 0; i < n; ++i) {
				while (b.top() > a[i]) {
					int x = b.top();
					b.pop();
					b.push(x / 2);
				}

				if (b.top() < a[i])
					return false;
				b.pop();
			}

			return true;
		}() ? "YES" : "NO") << "\n";
    }
}