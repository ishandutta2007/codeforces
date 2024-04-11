#include <iostream>
using namespace std;

int a, b, c, d;

int main()
{
	cin >> a >> b >> c >> d;
	int x = min(a, min(c, d));
	a -= x;
	int y = min(a, b);
	cout << x * 256 + y * 32 << endl;

	return 0;
}