#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
const int N=200050;
vector<int> sol[N];
int ans,c1,c0,S1[N],S0[N];
char s[N];
int main()
{
	int n,i,j;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]=='1')
		{
			if(!c0) return printf("-1\n"),0;
			sol[S0[c0]].push_back(i);
			S1[++c1]=S0[c0];
			c0--;
		}
		else
		{
			if(c1)
			{
				sol[S1[c1]].push_back(i);
				S0[++c0]=S1[c1];
				c1--;
			}
			else
			{
				sol[++ans].push_back(i);
				S0[++c0]=ans;
			}
		}
	}
	if(c1) return printf("-1\n"),0;
	printf("%i\n",ans);
	for(i=1;i<=ans;i++)
	{
		printf("%i ",sol[i].size());
		for(j=0;j<sol[i].size();j++) printf("%i ",sol[i][j]);
		printf("\n");
	}
	return 0;
}