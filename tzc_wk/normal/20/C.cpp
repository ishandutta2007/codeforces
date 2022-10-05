#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>
#define inf (long long)1e15
using namespace std;
const int maxn=100001;
int n,m,i,a,b,c,j,p[maxn];
vector <pair<int,long long> >g[maxn];
vector <long long> path,d(maxn,inf);
set<pair<long long,int> >q;
int main()
{
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b>>c;
		g[a].push_back(make_pair(b,c));
		g[b].push_back(make_pair(a,c));
	}
	d[1]=0;
	q.insert(make_pair(0,1));
	while (!q.empty())
	{
		int v=q.begin()->second;
		q.erase(q.begin());
		for (j=0;j<g[v].size();j++)
		{
			int to=g[v][j].first;
			int len=g[v][j].second;
			if (d[to]>d[v]+len)
			{
				q.erase(make_pair(d[to],to));
				d[to]=d[v]+len;
				p[to]=v;
				q.insert(make_pair(d[to],to));
			}   	
		}
	}
	int a=n;
	while (1)
	{
		path.push_back(a);
		a=p[a];
		if (a==0)
		break;
	}
	if (path[path.size()-1]!=1)
	{
		cout<<-1;
		return 0;}
	for (i=path.size()-1;i>=0;i--)
		cout<<path[i]<<" ";  
	return 0;
}