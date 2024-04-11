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
#define N 1005
using namespace std;
int tab[N][N];
int akt[N][N];
int ok[N][N];
vector<int> tmp;
int main()
{
	// nie zapomnij o ll
	ios_base::sync_with_stdio(0);
	int n, m;
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin>>tab[i][j];
		}
	}
	int kl = 0, kp = 1000*1000*1000, aktc, faj = -1;
	while (kl <= kp)
	{
		aktc = (kl + kp) / 2;
		for (int i = 1; i <= max(n,m); i++)
		{
			for (int j = 1; j <= max(m, n); j++)
			{
				ok[i][j] = 0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			tmp.clear();
			for (int j = 1; j <= m; j++)
			{
				if (tab[i][j] >= aktc)
				{
					for (int k = 0; k < tmp.size(); k++)
					{
						if (ok[tmp[k]][j] == 1)
						{
							faj = aktc;
							kl = aktc + 1;
							goto A;
						}
						ok[tmp[k]][j] = 1;
					}
					tmp.push_back(j);
				}
			}
				
		}
		kp = aktc - 1;
		A: ;
	}
	cout<<faj<<endl;
	
	// nie zapomnij o ll
	return 0;
}