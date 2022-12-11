#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int mod = (int)1e9 + 7;
int add(int a, int b)
{
	return (a + b < mod ? a + b : a + b - mod);
}

int dp[1000][3][3];

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	int n;
	string str;	
	cin >> str;
	n = str.length();

	dp[0][0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		int xNum = (str[i] - '0');
		for (int eq1 = 0; eq1 < 2; eq1++)
			for (int eq2 = 0; eq2 < 2; eq2++)
			{
				for (int num1 = 0; num1 < 2; num1++)
					for (int num2 = 0; num2 < 2; num2++)
					{
						if (eq1 == 0 && num1 > num2)
							continue;		
						if (eq2 == 0 && (num1 ^ xNum) < (num2 ^ xNum))
							continue;
						if (num1 == num2)
						{
							int nEq = (eq2 == 1 ? 1 : ((num1 ^ xNum) > (num2 ^ xNum)));
							dp[i + 1][eq1][nEq] = add(dp[i + 1][eq1][nEq], dp[i][eq1][eq2]);
						}
						else if (num1 < num2)
						{
							int nEq = (eq2 == 1 ? 1 : ((num1 ^ xNum) > (num2 ^ xNum)));
							dp[i + 1][1][nEq] = add(dp[i + 1][1][nEq], dp[i][eq1][eq2]);
						}
						else
						{
							int nEq = (eq2 == 1 ? 1 : ((num1 ^ xNum) > (num2 ^ xNum)));
							dp[i + 1][1][nEq] = add(dp[i + 1][1][nEq], dp[i][eq1][eq2]);
						}
					}
			}	
	}
           
    cout << dp[n][1][1];
	
	return 0;
}