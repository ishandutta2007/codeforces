#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
using namespace std;
#define pb push_back
const int N=505;
bool dp[N][N];
int go[N][N];
vector<int> sol;
bool Make(vector<int> x, int n, bool t)
{
	int i,j;
	dp[0][0]=1;
	//if(!t) printf("%i %i\n",x.size(),n);
	for(i=0;i<x.size();i++)
	{
		for(j=0;j<=n;j++)
		{
			dp[i+1][j]=dp[i][j];go[i+1][j]=0;
			if(x[i]<=j)
			{
				dp[i+1][j]|=dp[i][j-x[i]];
				if(dp[i][j-x[i]]) go[i+1][j]=1;
			}
			//if(!t) printf("%i ",dp[i][j]);
		}
		//if(!t) printf("\n");
	}
	if(t)
	{
		sol.clear();
		if(dp[x.size()][n])
		{
			i=x.size();j=n;
			while(i>0 && j>0)
			{
				//printf("%i %i\n",i,j);
				if(go[i][j]) sol.pb(i),j-=x[i-1];
				i--;
			}
			reverse(sol.begin(),sol.end());
		}
	}
	//if(!t) printf(":D\n");
	return dp[x.size()][n];
}
int main()
{
	srand(time(0));
	int n,k,i,j;
	scanf("%i %i",&n,&k);
	vector<int> all;all.resize(n);
	for(i=0;i<n;i++) scanf("%i",&all[i]);
	sort(all.begin(),all.end());
	vector<int> ret;
	for(i=0;i<=k;i++)
	{
		vector<int> tmp;
		int Try=5000/n;
		while(Try--)
		{
			random_shuffle(all.begin(),all.end());
			tmp.clear();
			if(Make(all,i,1))
			{
				int l=0;
				//for(j=0;j<sol.size();j++) printf("%i ",sol[j]);printf("\n");
				for(j=0;j<all.size();j++)
				{
					if(l<sol.size() && sol[l]==j+1)
					{
						l++;
					}
					else tmp.pb(all[j]);
				}
				//for(j=0;j<tmp.size();j++) printf("%i ",tmp[j]);printf("\n");
				//printf("%i\n",i);
				if(Make(tmp,k-i,0)){ ret.pb(i);break;}
			}
		}
	}
	printf("%i\n",ret.size());
	for(i=0;i<ret.size();i++) printf("%i ",ret[i]);
	printf("\n");
	return 0;
}