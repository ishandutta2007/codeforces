#include <stdio.h>
#include <vector>
using namespace std;
const int N=3050;
int p[N],r[N];
vector< pair<int,int> > sol1,sol2;
int Find(int x)
{
	if(p[x]!=x)
		p[x]=Find(p[x]);
	return p[x];
}
void Union(int u, int v)
{
	int x=Find(u);
	int y=Find(v);
	if(r[x]>r[y]) p[y]=x;
	if(r[x]<r[y]) p[x]=y;
	if(r[x]==r[y]) r[x]++,p[y]=x;
}
int main()
{
	int n,u,v,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) p[i]=i;
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		if(Find(u)==Find(v))
		{
			sol1.push_back(make_pair(u,v));
		}
		else Union(u,v);
	}
	//for(i=1;i<=n;i++) printf("%i ",p[i]);
	//printf("%i\n:D",sol1.size());
	for(u=1;u<=n;u++)
	{
		for(v=u+1;v<=n;v++)
		{
			//printf("%i %i\n",p[u],p[v]);
			if(Find(u)!=Find(v))
			{
				sol2.push_back(make_pair(Find(u),Find(v)));
				Union(Find(u),Find(v));
			}
		}
	}
	printf("%i\n",sol1.size());
	for(i=0;i<sol1.size();i++) printf("%i %i %i %i\n",sol1[i].first,sol1[i].second,sol2[i].first,sol2[i].second);
	return 0;
}