#include <cstdio>
#include <iostream>
#include <utility>
#include <cstring>
#include <algorithm>

typedef std::pair<int, int> ii;
typedef std::pair<double, double> dd;

const int inf = 10000;

inline int readint()
{
	int temp;
	scanf("%i",&temp);
	return temp;
}

int a[200];

int memo[200][3];//0=rest, 1=contest, 2=gym
int n;

int dp(int day, int act)
{
	if(day==n) return 0;
	if(memo[day][act]!=-1) return memo[day][act];
	int &res=memo[day][act];
	res=inf;
	if((act==1 && (a[day]==0 || a[day]==2)) || (act==2 && (a[day]==0 || a[day]==1)))
		return res;
	if(act==0)
	{
		res=std::min(res, 1+dp(day+1, 0));
		res=std::min(res, 1+dp(day+1, 1));
		res=std::min(res, 1+dp(day+1, 2));
	}
	else if(act==1)
	{
		res=std::min(res, dp(day+1, 0));
		res=std::min(res, dp(day+1, 2));
	}
	else
	{
		res=std::min(res, dp(day+1, 0));
		res=std::min(res, dp(day+1, 1));
	}
	//printf("day %i act %i is %i.\n",day,act,res);
	return res;

}

int main()
{
	memset(memo, -1, sizeof memo);
	n=readint();
	for(int i=0;i<n;i++)
		a[i]=readint();
	int ans=dp(0, 0);
	ans=std::min(ans, dp(0, 1));
	ans=std::min(ans, dp(0, 2));
	printf("%i\n",ans);

}