#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=52;
int n,a[N];
pair<int,int> DP[2][N];
bool mark[2][N];
pair<int,int> Recur(int player, int pos)
{
	if(pos>n) return make_pair(0,0);
	if(mark[player][pos]) return DP[player][pos];
	mark[player][pos]=true;
	if(pos==n && player==1) DP[player][pos].second=a[pos];
	else if(pos==n && player==0) DP[player][pos].first=a[pos];
	else if(player==1)
	{
		int i,mass=0;
		pair<int,int> sol,tmp;
		sol.first=0;
		sol.second=0;
		for(i=pos;i<=n;i++)
		{
			tmp=Recur(player^1,i+1);
			tmp.second+=a[i];
			tmp.first+=mass;
			if(tmp.second>sol.second) sol=tmp;
			mass+=a[i];
		}
		DP[player][pos]=sol;
	}
	else
	{
		int i,mass=0;
		pair<int,int> sol,tmp;
		sol.first=0;
		sol.second=0;
		for(i=pos;i<=n;i++)
		{
			tmp=Recur(player^1,i+1);
			tmp.first+=a[i];
			tmp.second+=mass;
			if(tmp.first>sol.first) sol=tmp;
			mass+=a[i];
		}
		DP[player][pos]=sol;
	}
	return DP[player][pos];
}
int main()
{
	int i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	Recur(0,1);
	printf("%i %i\n",DP[0][1].second,DP[0][1].first);
	return 0;
}