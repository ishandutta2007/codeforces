#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=105;
int girls[N];
int boys[N];
int sol;
int main()
{
	int n,m,i,j,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&boys[i]);
	scanf("%i",&m);
	for(i=1;i<=m;i++) scanf("%i",&x),girls[x]++;
	sort(boys+1,boys+1+n);
	for(i=1;i<=n;i++)
	{
		if(girls[boys[i]-1])
		{
			sol++;
			girls[boys[i]-1]--;
		}
		else if(girls[boys[i]])
		{
			sol++;
			girls[boys[i]]--;
		}
		else if(girls[boys[i]+1])
		{
			sol++;
			girls[boys[i]+1]--;
		}
	}
	printf("%i\n",sol);
	return 0;
}