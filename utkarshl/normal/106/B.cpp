#include"stdio.h"
#include"algorithm"
using namespace std;
struct laptop
{
	int a,b,c,d,i;
	bool operator<(const laptop s)const 
	{
		return d<s.d;
	}
};
int main()
{
	int n;
	scanf("%d",&n);
	laptop l[n];
	for(int x=0;x<n;x++)
	{
		scanf("%d%d%d%d",&l[x].a,&l[x].b,&l[x].c,&l[x].d);
		l[x].i=x+1;
	}
	int best=0,cost=10000;
	for(int x=0;x<n;x++)
	{
		for(int y=0;y<n;y++)
		{
			if(l[y].i<0)continue;
			if(l[x].a<l[y].a && l[x].b<l[y].b && l[x].c<l[y].c)
			{
				l[x].i=-1;
			}
		}
		if(l[x].i>=0&& l[x].d<cost)
		{
			cost=l[x].d;
			best=x+1;
		}
	}
	printf("%d",best);
}