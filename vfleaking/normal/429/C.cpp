#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	static int a[24];

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int allOne = 0;
	int tn = 0;
	for (int i = 0; i < n; i++)
		if (a[i] == 1)
			allOne++;
		else
			a[tn++] = a[i];
	n = tn;

	const int MaxN = 12;
	static int cntOne[1 << MaxN];
	static bool canTr[1 << MaxN][25];
	static bool canF[1 << MaxN][25];

	if (n > MaxN)
	{
		cout << "NO" << endl;
		return 0;
	}

	for (int sta = 0; sta < (1 << n); sta++)
		cntOne[sta] = cntOne[sta >> 1] + (sta & 1);

	for (int sta = 0; sta < (1 << n); sta++)
		for (int n1 = 0; n1 <= allOne; n1++)
		{
			if (sta == 0)
			{
				canTr[sta][n1] = n1 == 1;
				canF[sta][n1] = n1 >= 2;
			}
			else
			{
				canTr[sta][n1] = false;
				for (int r = 0; r < n; r++)
					if ((sta >> r & 1) && cntOne[sta] + n1 == a[r] && canF[sta ^ 1 << r][n1])
						canTr[sta][n1] = true;

				canF[sta][n1] = false;
				int sub = sta;
				while (true)
				{
					for (int m1 = 0; m1 <= n1; m1++)
						if (canTr[sub][m1] && (canTr[sta ^ sub][n1 - m1] || canF[sta ^ sub][n1 - m1]))
							canF[sta][n1] = true;

					if (sub == 0)
						break;
					sub = (sub - 1) & sta;
				}
			}
		}

	if (canTr[(1 << n) - 1][allOne])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}