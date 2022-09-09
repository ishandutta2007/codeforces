#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=105;
const int inf=1e9+7;
int dp[N][N][2],tmp[N][N][2];
int p[N];
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<=n;i++) scanf("%i",&p[i]);
	int even=n/2,odd=n-even;
	/*for(int i=1;i<=n;i++)
	{
		if(p[i]!=0)
		{
			if(p[i]&1) odd--;
			else even--;
		}
	}*/
	for(int e=0;e<=even;e++)
	{
		for(int o=0;o<=odd;o++)
		{
			for(int las=0;las<2;las++)
			{
				dp[e][o][las]=inf;
			}
		}
	}
	dp[0][0][0]=dp[0][0][1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int e=0;e<=even;e++)
		{
			for(int o=0;o<=odd;o++)
			{
				for(int las=0;las<2;las++)
				{
					tmp[e][o][las]=inf;
				}
			}
		}

		if(p[i]==0 || p[i]%2==0)
		{
			for(int e=1;e<=even;e++)
			{
				for(int o=0;o<=odd;o++)
				{
					ckmn(tmp[e][o][0],dp[e-1][o][1]+1);
					ckmn(tmp[e][o][0],dp[e-1][o][0]);
				}
			}
		}
		if(p[i]==0 || p[i]%2==1)
		{
			for(int e=0;e<=even;e++)
			{
				for(int o=1;o<=odd;o++)
				{
					ckmn(tmp[e][o][1],dp[e][o-1][0]+1);
					ckmn(tmp[e][o][1],dp[e][o-1][1]);
				}
			}
		}

		for(int e=0;e<=even;e++)
		{
			for(int o=0;o<=odd;o++)
			{
				for(int las=0;las<2;las++)
				{
					dp[e][o][las]=tmp[e][o][las];
				}
			}
		}
	}
	printf("%i\n",min(dp[even][odd][0],dp[even][odd][1]));
	return 0;
}