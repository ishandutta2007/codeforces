#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int x;
	cin >> x;
	if (x % 2 == 0 and x != 2)
	{
		cout << "YES";
		return 0;
	}
	cout << "NO";
	return 0;
}