#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
bool Check(int x, int y)
{
	int sum=x;
	while(x>0)
	{
		sum+=x%10;
		x/=10;
	}
	return sum==y;
}
vector<int> sol;
int main()
{
	int x,i;
	scanf("%i",&x);
	for(i=x;i>0 && i>=x-10000;i--)
	{
		if(Check(i,x)) sol.push_back(i);
	}
	sort(sol.begin(),sol.end());
	printf("%i\n",sol.size());
	for(i=0;i<sol.size();i++) printf("%i ",sol[i]);
	return 0;
}