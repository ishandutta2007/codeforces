#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

int main()
{
	int n;
	s64 res;
	cin >> n;
	
	if (n <= 2)
		res = n;
	else if (n % 2 == 1)
		res = (s64)n * (n - 1) * (n - 2);
	else if (n % 6 == 0)
		res = (s64)(n - 1) * (n - 2) * (n - 3);
	else
		res = (s64)n * (n - 1) * (n - 3);
	cout << res << endl;
	
	return 0;
}