#include <stdio.h>
#include <vector>
using namespace std;
//vector<int> penguins;
int ksor(vector<int> penguins)
{
	if(penguins.size()==0) return 0;
	printf("? %i",penguins.size());
	int i;
	for(i=0;i<penguins.size();i++)
		printf(" %i",penguins[i]);
	printf("\n");
	fflush(stdout);
	int res;
	scanf("%i",&res);
	return res;
}
int p1,p2,pp,in;
int main()
{
	int n,x,y,i,j;
	scanf("%i %i %i",&n,&x,&y);
	for(i=0;i<10;i++)
	{
		//if(!penguins.empty()) penguins.clear();
		vector<int> penguins;
		for(j=1;j<=n;j++)
		{
			if(j&(1<<i)) penguins.push_back(j);
		}
		int u=ksor(penguins);
		if(u==y || u==(x^y))
		{
			pp|=1<<i;
			in=i;
		}
	}
	for(i=0;i<10;i++)
	{
		if(i==in) continue;
		//if(!penguins.empty()) penguins.clear();
		vector<int> penguins;
		for(j=1;j<=n;j++)
		{
			if(j&(1<<in)) continue;
			if(j&(1<<i)) penguins.push_back(j);
		}
		int u=ksor(penguins);
		if(u==y || u==(x^y))
		{
			p1|=1<<i;
		}
	}
	p2=p1^pp;
	if(p2<p1) printf("! %i %i\n",p2,p1);
	else printf("! %i %i\n",p1,p2);
	return 0;
}