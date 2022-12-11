#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int a[2000];

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	int cntP = 0, cntM = 0;
	bool zero = false;

	int sum = 0;
	int minA = (int)1e9;
	for (int i = 0; i < 2 * n - 1; i++)
	{
		cin >> a[i];          
		if (a[i] < 0)
			cntM++;
		else if (a[i] > 0)
			cntP++;
		else
			zero = true;
		sum += abs(a[i]);
		minA = min(minA, abs(a[i]));
	}

	if (n % 2 == 1 || zero)
		cout << sum;
	else
	{
		if (cntM % 2 == 1)
			cout << sum - 2 * minA;
		else
			cout << sum;
	}

	return 0;
}