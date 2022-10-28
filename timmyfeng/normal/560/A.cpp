#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int n;
    cin >> n;

    bool ok = false;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ok |= (a == 1);
    }

    cout << (ok ? -1 : 1) << "\n";
}