#include <iostream>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	int y, b, r;
	cin >> y >> b >> r;
	int ans = INF;
	ans = min(ans, r + r - 1 + r - 2);
	ans = min(ans, b + b + 1 + b - 1);
	ans = min(ans, y + y + 1 + y + 2);
	cout << ans << endl; 
	return 0;
}