#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

const int MaxN = 100000;

int main()
{
	int n;
	static int a[1 + MaxN];
	static int b[1 + MaxN];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		b[i] = a[i];

	sort(b + 1, b + n + 1);

	int t = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] != b[i])
			t++;

	if (t <= 2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}