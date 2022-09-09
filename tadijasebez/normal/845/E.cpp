#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int abs(int x){ return x<0?-x:x;}
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int P[550][2];
vector<int> Points;
vector<pair<int,int> > Segments;
bool Check(int t, int x, int y, int n, int m, int k)
{
	Points.clear();
	Points.push_back(0);
	Points.push_back(n-1);
	int i,j;
	for(i=0;i<k;i++)
	{
		if(P[i][x]-t>0)
		{
			Points.push_back(P[i][x]-t);
			Points.push_back(P[i][x]-t-1);
		}
		if(P[i][x]+t<n-1)
		{
			Points.push_back(P[i][x]+t);
			Points.push_back(P[i][x]+t+1);
		}
	}
	sort(Points.begin(),Points.end());
	Points.erase(unique(Points.begin(),Points.end()),Points.end());
	int minp=n-1;
	int maxp=0;
	for(i=0;i<Points.size();i++)
	{
		Segments.clear();
		for(j=0;j<k;j++)
		{
			if(abs(P[j][x]-Points[i])<=t)
			{
				Segments.push_back(make_pair(P[j][y]-t,P[j][y]+t+1));
			}
		}
		sort(Segments.begin(),Segments.end());
		int last=0;
		for(j=0;j<Segments.size();j++)
		{
			if(Segments[j].first>last)
				break;
			last=Segments[j].second;
		}
		if(last<m)
		{
			minp=min(minp,Points[i]);
			maxp=max(maxp,Points[i]);
		}
	}
	return maxp-minp<=2*t;
}
int main()
{
	int k,i,n,m;
	scanf("%i %i %i",&n,&m,&k);
	for(i=0;i<k;i++)
	{
		scanf("%i %i",&P[i][0],&P[i][1]);
		P[i][0]--;
		P[i][1]--;
	}
	int top=1e9+7,bot=0,mid;
	int sol=1e9+7;
	while(top>=bot)
	{
		mid=(top+bot)>>1;
		if(Check(mid,0,1,n,m,k) && Check(mid,1,0,m,n,k)) sol=mid,top=mid-1;
		else bot=mid+1;
	}
	printf("%i\n",sol);
	return 0;
}