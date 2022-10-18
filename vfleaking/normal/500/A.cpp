#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 30000;

int main()
{
	int n, t;
	static int a[MaxN + 1];

	cin >> n >> t;
	for (int i = 1; i <= n - 1; i++)
		scanf("%d", &a[i]);

	static bool book[MaxN + 1];
	book[1] = true;
	for (int i = 1; i <= n - 1; i++)
		if (book[i])
			book[i + a[i]] = true;

	if (book[t])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}