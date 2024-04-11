#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
vector< pair<int,int> > flats;
vector<int> sol;
int main()
{
	int n,m,i,u,v;
	scanf("%i %i",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%i %i",&u,&v);
		flats.push_back(make_pair(u,v));
	}
	sort(flats.begin(),flats.end());
	int t;
	int ok=0;
	for(t=1;t<=100;t++)
	{
		bool tmp=true;
		for(i=0;i<flats.size();i++)
		{
			if((flats[i].first+t-1)/t!=flats[i].second) tmp=false;
		}
		if(tmp) ok++,sol.push_back(t);
	}
	if(ok==0) printf("-1\n");
	else
	{
		int ans=(n+sol[0]-1)/sol[0];
		for(i=1;i<sol.size();i++)
		{
			if((n+sol[i]-1)/sol[i]!=ans)
			{
				printf("-1\n");
				return 0;
			}
		}
		printf("%i\n",ans);
		//if(ok==1) printf("%i\n",(n+sol-1)/sol);
		//else printf("-1\n");
	}
	return 0;
}