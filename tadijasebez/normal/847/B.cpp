#include <stdio.h>
#include <vector>
using namespace std;
const int N=200050;
int k;
vector<int> sol[N];
void Set(int x)
{
	int top=k-1;
	int bot=0,mid,t=k;
	while(top>=bot)
	{
		mid=top+bot>>1;
		if(sol[mid][sol[mid].size()-1]<x) t=mid,top=mid-1;
		else bot=mid+1;
	}
	//printf("%i\n",t);
	if(t==k)
	{
		sol[k].push_back(x);
		k++;
	}
	else
	{
		sol[t].push_back(x);
	}
}
int main()
{
	int n,i,j;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%i",&i);
		Set(i);
	}
	for(i=0;i<k;i++)
	{
		for(j=0;j<sol[i].size();j++) printf("%i ",sol[i][j]);
		printf("\n");
	}
	return 0; 
}