#include <stdio.h>
#include <vector>
using namespace std;

bool d[501][501][501];
int c[501];

int main()
{
	int n, k; scanf("%d%d",&n,&k);
	for (int i = 1; i <= n; i++) scanf("%d",&c[i]);

	d[0][0][0] = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			for (int m = 0; m <= j; m++)
			{
				d[i][j][m] = d[i-1][j][m];
				if (j>=c[i]) d[i][j][m] |= d[i-1][j-c[i]][m];
				if (m>=c[i]) d[i][j][m] |= d[i-1][j-c[i]][m-c[i]];
			}
		}
	}

	vector<int> ans;
	for (int i = 0; i <= k; i++)
	{
		if (d[n][k][i]) ans.push_back(i);
	}
	printf("%d\n", (int)ans.size());
	for (int t : ans) printf("%d ", t);
}