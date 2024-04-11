#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int a[1000];

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	int st = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++)	
	{
		scanf("%d", &a[i]);
		if (a[i] == 0)
			cnt++;
		if (a[i] < 0)
			st++;
	}

	sort(a, a + n);                            
	cout << 1 << ' ' << a[0];    

	int m = (st % 2 == 0 ? 2 : 1);
	cout << endl << n - cnt - m << ' ';
	for (int i = m; i < n; i++)
	{
		if (a[i] != 0)
			cout << a[i] << ' ';
	}

	if (m == 2)
		cout << endl << cnt + 1 << ' ';
	else
		cout << endl << cnt << ' ';
	for (int i = 0; i < n; i++)	
	{
		if (a[i] == 0)
			cout << 0 << ' ';
	}
	if (m == 2)
		cout << a[1];

	return 0;
}