#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<set>
#include<map>
#include<iostream>
#include<ctime>
#include<queue>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define LL long long
#define PB push_back

string s, p;
int dp[2002][2002];
int res[2002];

pair<int, int> check(int x)
{
	int ind=(int)p.size()-1, rem=0;
	while(ind>=0 && x>=0)
	{
		if(s[x]==p[ind])
		{
			x--;
			ind--;
		}
		else
		{
			rem++;
			x--;
		}
	}
	if(ind!=-1) return MP(-1, -1);
	return MP(x+1, rem);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin >> s >> p;
	int n=(int)p.size(), m=(int)s.size(), maxi=(int)s.size()/(int)p.size();
	for(int i=1; i<2002; i++) dp[0][i]=1000000000;
	for(int i=0; i<m; i++)
	{
		dp[i+1][0]=0;
		pair<int, int> pop=MP(-1, -1);
		if(s[i]==p[n-1]) pop=check(i);
		if(pop.F!=-1)
		{
		//	dp[i+1][1]=min(pop.S, dp[i][1]);
			for(int j=1; j<=maxi; j++) dp[i+1][j]=min(dp[i][j], dp[pop.F][j-1]+pop.S);
		}
		else for(int j=1; j<=maxi; j++) dp[i+1][j]=dp[i][j];
	}
	int ind=0;
	for(int j=maxi+1; j<2002; j++) dp[m][j]=1000000000;
	for(int i=0; i<=m; i++)
	{
		while(dp[m][ind+1]<=i) ind++;
		//printf("%d ", min(ind, (m-i)/n));
		cout<< min(ind, (m-i)/n) << ' ';
	}
	cout<< '\n';
	return 0;
}