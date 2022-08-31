#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#define uint long long int
#define MP make_pair
#define PB push_back
#define N 1004
using namespace std;
int zx[N];
int zy[N];

int main()
{
	// nie zapomnij o ll
	ios_base::sync_with_stdio(0);
	int n, m;
	cin>>n>>m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin>>x>>y;
		zx[x] = 1;
		zy[y] = 1;
	}
	zx[1] = zx[n] = 1;
	zy[1] = zy[n] = 1;
	int result = 0;
	for (int i = 2; i <= n / 2; i++)
	{
		int sum = zx[i] + zy[i] + zx[n - i + 1] + zy[n - i + 1];
		/* if (sum <= 2)
		{
			result += 2;
		}
		else
		{
			if (sum == 3)
			{
				result += 1;
			}
		} */
		result += 4 - sum;
	}
	if (n%2 == 1)
	{
		int sr = n/2 + 1;
		if (!zx[sr] || !zy[sr])
		{
			result++;
		}
	}
	cout<<result<<endl;
	
	// nie zapomnij o ll
	return 0;
}