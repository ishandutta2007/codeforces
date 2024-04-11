#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int s = 1; s < n; s++)
	{
		int t = n - s;
		bool okS = true;
		for (int i = 2; i * i <= s; i++)
			if (s % i == 0)
			{
				okS = false;
				break;
			}
		if (okS)
			continue;
		bool okT = true;
		for (int i = 2; i * i <= t; i++)
			if (t % i == 0)
			{
				okT = false;
				break;
			}
		if (okT)
			continue;
		cout << s << " " << t << endl;
		break;
	}

	return 0;
}