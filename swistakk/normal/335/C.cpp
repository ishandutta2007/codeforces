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
#define N 105

using namespace std;

int zak[N][2];
int nim[N][3][3];
vector<int> tmp[N][3][3];

int main()
{
	// nie zapomnij o ll
	ios_base::sync_with_stdio(0);
	int r, n;
	cin>>r>>n;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		cin>>y>>x;
		zak[y][x - 1] = 1;
	}
	
	nim[1][0][0] = 1;
	nim[2][0][0] = 0;
	nim[2][1][0] = nim[2][2][0] = nim[2][0][1] = nim[2][0][2] = 1;
	for (int i = 3; i <= r; i++)
	{
		for (int j = 2; j >= 0; j--)
		{
			for (int k = 2; k >= 0; k--)
			{
				if (j == 0)
				{
					tmp[i][j][k].PB(nim[i][1][k]);
					tmp[i][j][k].PB(nim[i][2][k]);
				}
				if (k == 0)
				{
					tmp[i][j][k].PB(nim[i][j][1]);
					tmp[i][j][k].PB(nim[i][j][2]);
				}
				for (int l = 2; l <= i - 1; l++)
				{
					if (!((j == 1 && l == 2) || (k == 1 && l == i - 1)))
					{
						tmp[i][j][k].PB(nim[l][j][2] ^ nim[i - l + 1][2][k]);
					}
					if (!((j == 2 && l == 2) || (k == 2 && l == i - 1)))
					{
						tmp[i][j][k].PB(nim[l][j][1] ^ nim[i - l + 1][1][k]);
					}
				}
				sort(tmp[i][j][k].begin(), tmp[i][j][k].end());
				if (tmp[i][j][k].empty() || tmp[i][j][k][0])
				{
					nim[i][j][k] = 0;
				}
				else
				{
					int act = 0;
					for (int l = 1; l < tmp[i][j][k].size(); l++)
					{
						if (tmp[i][j][k][l] >= tmp[i][j][k][l - 1] + 2)
						{
							nim[i][j][k] = tmp[i][j][k][l - 1] + 1;
							goto A;
						}
					}
					nim[i][j][k] = tmp[i][j][k].back() + 1;
					A: ;
				}
			}
		}
	}
	if (n == 0)
	{
		if (nim[r][0][0])
		{
			cout<<"WIN"<<endl;
		}
		else
		{
			cout<<"LOSE"<<endl;
		}
		return 0;
	}
	int actxor = 0;
	int lastrow = 1;
	int j;
	bool init = false;
	for (int i = 1; i <= r; i++)
	{
		if (zak[i][0] || zak[i][1])
		{
			if (!init)
			{
				init = true;
				lastrow = i;
				if (zak[i][0])
				{
					j = 1;
				}
				else
				{
					j = 2;
				}
				if (i > 1)
				{
					actxor = nim[i][0][1];
				}
			}
			else
			{
				int k;
				if (zak[i][0])
				{
					k = 1;
				}
				else
				{
					k = 2;
				}
				actxor = (actxor ^ nim[i - lastrow + 1][j][k]);
				lastrow = i;
				j = k;
			}
		}
	}
	if (lastrow < r)
	{
		actxor = (actxor ^ nim[r - lastrow + 1][j][0]);
	}
	if (actxor)
	{
		cout<<"WIN"<<endl;
	}
	else
	{
		cout<<"LOSE"<<endl;
	}
	
	
	// nie zapomnij o ll
	return 0;
}