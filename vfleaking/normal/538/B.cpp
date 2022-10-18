#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int d_n = 0;
	static int d[10];
	while (n > 0)
		d[d_n++] = n % 10, n /= 10;

	vector<int> res;
	for (int i = 1; i <= 9; i++)
	{
		int x = 0;
		for (int k = d_n - 1; k >= 0; k--)
		{
			x = x * 10;
			if (d[k] >= i)
				x++;
		}
		if (x)
			res.push_back(x);
	}

	cout << res.size() << endl;
	for (int i = 0; i < (int)res.size(); i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}