#include<bits/stdc++.h>
const int N = 25;
int main()
{
	int n, m, num1[N][N], num2[N][N];
	bool flag = false;
	memset(num1, 0, sizeof(num1));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &num1[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= m; j++)
			if (num1[i][j] != j)
				num1[i][0]++;
	bool flag1 = true;
	for (int i = 0; i < n; i++)
		if (num1[i][0] > 2)
			flag1 = false;
	if (flag1)
		flag = true;
	for (int x = 1; x < m; x++)
		for (int y = x + 1; y <= m; y++)
		{
			memset(num2, 0, sizeof(num2));
			for (int i = 0; i < n; i++)
				for (int j = 1; j <= m; j++)
					if (j == x)
						num2[i][j] = num1[i][y];
					else if (j == y)
						num2[i][j] = num1[i][x];
					else
						num2[i][j] = num1[i][j];
			for (int i = 0; i < n; i++)
				for (int j = 1; j <= m; j++)
					if (num2[i][j] != j)
						num2[i][0]++;
			flag1 = true;
			for (int i = 0; i < n; i++)
				if (num2[i][0] > 2)
					flag1 = false;
			if (flag1)
				flag = true;
		}
	if (flag)
		printf("YES");
	else
		printf("NO");
	return 0;
}