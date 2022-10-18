#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	cin >> n;
	
	if (n == 1)
	{
		cout << 1 << endl;
		cout << 1 << ' ' << 1 << endl;
		return 0;
	}
	
	int i = 2;
	
	int res = 0;
	for (int j = 2; j / 2 < n; j <<= 1)
		res++;
	cout << res << endl;
	while (i / 2 < n)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
			if (j % i < i / 2)
				cnt++;
		cout << cnt << ' ';
		for (int j = 1; j <= n; j++)
			if (j % i < i / 2)
				cout << j << ' ';
		cout << endl;
		
		i <<= 1;
	}
	
	return 0;
}