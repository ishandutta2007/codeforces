#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << 2 * (max(abs(a - c), 1) + 1 + max(abs(b - d), 1) + 1) << '\n';	
	return 0;
}