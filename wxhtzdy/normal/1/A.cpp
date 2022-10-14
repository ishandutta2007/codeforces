#include <bits/stdc++.h>

using namespace std;

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	cout << ((a + c - 1) / c) * ((b + c - 1) / c) << endl;
}