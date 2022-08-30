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
int lab[N][N];
int kand[N];
int inv;
int ok;
void Try(int n)
{
	for (int i = 1; i <= n; i++)
	{
		kand[i] = 0;
		for (int j = 1; j <= n; j++)
		{
			if (lab[i][j] == 0)
			{
				kand[i] = j;
			}
		}
		if (kand[i] == 0)
		{
			return;
		}
	}
	ok = 1;
	for (int i = 1; i <= n; i++)
	{
		if (!inv)
		{
		cout<<i<<" "<<kand[i]<<endl;
		}
		else
		{
			cout<<kand[i]<<" "<<i<<endl;
		}
	}
}
void trans(int n)
{
	inv = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			swap(lab[i][j], lab[j][i]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	for (int i = 1; i <= n;i++)
	{
		for (int j = 1; j <= n; j++)
		{
			char c;
			cin>>c;
			if (c=='E')
			{
				lab[i][j] = 1;
			}
		}
	}
	Try(n);
	if (ok)
	{
		return 0;
	}
	trans(n);
	Try(n);
	if (ok)
	{
		return 0;
	}
	cout<<"-1"<<endl;
	return 0;
}