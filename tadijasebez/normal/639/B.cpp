#include <stdio.h>
#include <vector>
using namespace std;
struct Edge
{
	int u,v;
	Edge (){}
	Edge (int a, int b)
	{
		u=a;
		v=b;
	}
};
vector<Edge> sol;
int main()
{
	int n,d,h,i;
	scanf("%i %i %i",&n,&d,&h);
	if(n<d || (d+1)/2>h || h>d || (d<2 && n>2))
	{
		printf("-1\n");
		return 0;
	}
	int m=2,prev=-1,now;
	bool ok=true;
	for(i=0;i<=d;i++)
	{
		if(d-i==h)
		{
			now=1;
			if(i==0) ok=false;
		}
		else now=m++;
		if(prev!=-1) sol.push_back(Edge(prev,now));
		prev=now;
	}
	if(ok) for(m;m<=n;m++) sol.push_back(Edge(1,m));
	else for(m;m<=n;m++) sol.push_back(Edge(2,m));
	for(i=0;i<sol.size();i++) printf("%i %i\n",sol[i].u,sol[i].v);
	return 0;
}