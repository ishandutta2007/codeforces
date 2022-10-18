#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int nCases;
	cin >> nCases;

	while (nCases--)
	{
		int n, p;
		cin >> n >> p;
		int rest = p + 2;
		for (int i = 2; i <= n; i++)
		{
			rest += 2;

			for (int k = 1; k < i && rest > 0; k++)
				cout << i << " " << k << endl, rest--;
		}
	}

	return 0;
}