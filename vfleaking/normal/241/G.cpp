#include <iostream>
using namespace std;

int main()
{
	cout << 500 << endl;
	cout << 0 << ' ' << 1000000 << endl;
	int x = 40000;
	for (int i = 498; i >= 1; i--)
	{
		cout << x << ' ' << i << endl;
		x += i + (i - 1);
	}
	cout << 1000000 << ' ' << 1000000 << endl;
	
	return 0;
}