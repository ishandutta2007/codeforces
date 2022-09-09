#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;
const int N=100050;
vector<int> X[N],Y[N];
set<int> was[N];
int x[N],y[N];
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&x[i],&y[i]);
		was[x[i]].insert(y[i]);
		X[x[i]].push_back(y[i]);
		Y[y[i]].push_back(x[i]);
	}
	for(i=0;i<N;i++) sort(X[i].begin(),X[i].end()),sort(Y[i].begin(),Y[i].end());
	int sol=0;
	for(i=1;i<=n;i++)
	{
		if(X[x[i]].size()<Y[y[i]].size())
		{
			if(X[x[i]].empty()) continue;
			for(j=0;j<X[x[i]].size() && y[i]>X[x[i]][j];j++)
			{
				int YY=X[x[i]][j];
				int len=y[i]-YY;
				if(x[i]-len<0) continue;
				sol+=(was[x[i]-len].count(YY)&&was[x[i]-len].count(y[i]));
			}
		}
		else
		{
			if(Y[y[i]].empty()) continue;
			for(j=0;j<Y[y[i]].size() && x[i]>Y[y[i]][j];j++)
			{
				int XX=Y[y[i]][j];
				int len=x[i]-XX;
				sol+=(was[XX].count(y[i]-len)&&was[x[i]].count(y[i]-len));
			}
		}
	}
	printf("%i\n",sol);
	return 0;
}