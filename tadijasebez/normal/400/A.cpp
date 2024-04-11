#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
vector< pair<int,int> > sol;
char word[20];
int main()
{
	int n,i,j,k;
	bool ok,oo;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%s",word+1);
		for(j=12;j;j--)
		{
			if(12%j==0)
			{
				oo=false;
				for(k=1;k<=j;k++)
				{
					ok=false;
					for(i=k;i<=12;i+=j) if(word[i]=='O') ok=true;
					if(!ok) oo=true;
				}
				if(oo) sol.push_back(make_pair(12/j,j));
			}
		}
		printf("%i ",sol.size());
		for(i=0;i<sol.size();i++) printf("%ix%i ",sol[i].first,sol[i].second);
		printf("\n");
		sol.clear();
	}
	return 0;
}