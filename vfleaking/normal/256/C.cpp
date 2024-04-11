#include <iostream>
#include <algorithm>
using namespace std;

const int MaxN = 77777;

const int MaxM = 881918;

typedef long long s64;

inline int getSG(const s64 &a)
{
	if (a <= 3ll)
		return 0;
	if (a <= 15ll)
		return 1;
	if (a <= 81ll)
		return 2;
	if (a <= 6723ll)
		return 0;
	if (a <= 50625ll)
		return 3;
	if (a <= 2562991875ll)
		return 1;
	return 2;
}

int main()
{
	int n;
	int res = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		s64 a;
		cin >> a;
		res ^= getSG(a);
	}

	if (res != 0)
		cout << "Furlo" << endl;
	else
		cout << "Rublo" << endl;

	return 0;
}