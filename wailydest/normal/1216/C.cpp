#include <iostream>
using namespace std;

int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;

bool f(int x, int y) 
{
	if (((x + 1 > x3 && x < x4) && (y + 1 > y3 && y < y4)) || ((x + 1 > x5 && x < x6) && (y + 1 > y5 && y < y6))) return false;
	return true;
}

int main() 
{
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
	
	for (int x = x1, y = y1; x < x2; ++x) 
	{
		if (f(x, y)) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	for (int x = x1, y = y1; y < y2; ++y) 
	{
		if (f(x, y)) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	for (int x = x1, y = y2 - 1; x < x2; ++x) 
	{
		if (f(x, y)) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	for (int x = x2 - 1, y = y1; y < y2; ++y) 
	{
		if (f(x, y)) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	cout << "NO\n";
	
	return 0;
}