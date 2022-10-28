#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << "9 8\n";
    } else {
        cout << 3 * n << ' ' << 2 * n << '\n';
    }
}