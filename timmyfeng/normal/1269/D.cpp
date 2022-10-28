#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	long long ctB = 0, ctW = 0;
	for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        if (i % 2) {
            ctW += a / 2;
            ctB += a - a / 2;
        } else {
            ctW += a - a / 2;
            ctB += a / 2;
        }
    }
    cout << min(ctB, ctW) << '\n';
}