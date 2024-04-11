#include <stdio.h>
#include <vector>
using namespace std;
vector<int> sol,sol1;
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,s,i,t;
	scanf("%i %i",&n,&s);
	for(i=1;i<=n;i++)
	{
		sol.push_back(min(s,9));
		s-=min(s,9);
	}
	if((sol.front()==0 && n>1) || s>0)
	{
		printf("-1 -1\n");
		return 0;
	}
	t=0;
	for(i=0;i<n;i++) sol1.push_back(sol[i]);
	for(i=0;i<n;i++) if(sol[i]>0) t=i;
	if(sol[n-1]==0)
	{
		sol1[n-1]=1;
		sol1[t]--;
	}
	for(i=n-1;i>=0;i--) printf("%i",sol1[i]);
	printf(" ");
	for(i=0;i<n;i++) printf("%i",sol[i]);
	printf("\n");
	return 0;
}