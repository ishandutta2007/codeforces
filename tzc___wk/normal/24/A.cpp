#include <bits/stdc++.h>
#include <vector>
using namespace std;
int n;
vector <pair <int,int> > num[110];
int cycle[110],sum=0;
struct road
{
	int begin,end,cost;
};
road r[110];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>r[i].begin>>r[i].end>>r[i].cost;
		r[i].begin--;r[i].end--;sum+=r[i].cost;
		num[r[i].begin].push_back(make_pair(r[i].end,0));
		num[r[i].end].push_back(make_pair(r[i].begin,r[i].cost));
	}
	int cur=0,pr=-1,q=0;
	for(int i=0;i<n;i++)
	{
		int city,cost;
		for(int j=0;j<2;j++)
		{
			city=num[cur][j].first;cost=num[cur][j].second;
			if(city!=pr)	break;
		}
		q+=cost;
		pr=cur;
		cur=city;
	}
	cout<<min(q,sum-q)<<endl;
	return 0;
}