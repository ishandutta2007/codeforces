#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	long double r = 0;
	for (int i = 1; i <= n; i++)
        r += 1.0L / i;
    cout << r << "\n";
}