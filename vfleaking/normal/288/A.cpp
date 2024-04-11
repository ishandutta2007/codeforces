#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 1000000;

int main()
{
	int n, k;
	static char s[MaxN + 1];

	cin >> n >> k;

	if (k == 1)
	{
		if (n == 1)
			cout << "a" << endl;
		else
			cout << "-1" << endl;
	}
	else if (k > n)
		cout << "-1" << endl;
	else
	{
		for (int i = 0; i < n - (k - 2); i++)
			s[i] = 'a' + i % 2;
		for (int i = 2; i < k; i++)
			s[n - k + i] = 'a' + i;

		cout << s << endl;
	}

	return 0;
}