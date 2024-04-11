#include <iostream>
using namespace std;

int main() 
{
	long long t, x, y, a, b;
	cin >> t;
	while (t--) 
	{
		cin >> x >> y >> a >> b;
		if (!((y - x) % (a + b))) cout << (y - x) / (a + b) << '\n';
		else cout << -1 << '\n';
	}
	return 0;
}