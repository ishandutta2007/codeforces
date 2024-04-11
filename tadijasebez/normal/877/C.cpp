#include <stdio.h>
#include <vector>
using namespace std;
vector<int> sol1,sol2;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i+=2) sol1.push_back(i);
	for(i=2;i<=n;i+=2) sol1.push_back(i);
	for(i=1;i<=n;i+=2) sol1.push_back(i);
	for(i=2;i<=n;i+=2) sol2.push_back(i);
	for(i=1;i<=n;i+=2) sol2.push_back(i);
	for(i=2;i<=n;i+=2) sol2.push_back(i);
	if(sol1.size()>sol2.size())
	{
		printf("%i\n",sol2.size());
		for(i=0;i<sol2.size();i++) printf("%i ",sol2[i]);
		printf("\n");
	}
	else
	{
		printf("%i\n",sol1.size());
		for(i=0;i<sol1.size();i++) printf("%i ",sol1[i]);
		printf("\n");
	}
	return 0;
}