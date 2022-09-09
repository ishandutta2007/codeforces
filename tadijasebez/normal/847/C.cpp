#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> sol;
int main()
{
	int n,i,j;
	long long k,t;
	scanf("%i %lld",&n,&k);
	t=1;
	while(t<n && t*(t+1)/2<=k) t++;
	//sol.push_back(t);
	n-=t;
	k-=t*(t-1)/2;
	for(i=t-1;i>=0;i--) while(k>=i && n>0) sol.push_back(i),k-=i,n--;
	sort(sol.begin(),sol.end());
	if(k) printf("Impossible\n");
	else
	{
		int j=0;
		for(i=0;i<t;i++)
		{
			while(j<sol.size() && sol[j]==i) printf("()"),j++;
			printf("(");
		}
		for(i=0;i<t;i++)
		{
			printf(")");
		}
	}
	return 0;
}