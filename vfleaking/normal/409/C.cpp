#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	
	int res = 100000;
	res = min(res, a / 1);
	res = min(res, b / 1);
	res = min(res, c / 2);
	res = min(res, d / 7);
	res = min(res, e / 4);

	cout << res << endl;

	return 0;
}