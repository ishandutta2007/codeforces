#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
vector<int> v[N];
int main()
{
	int n,k,m,i,x;
	scanf("%i %i %i",&n,&k,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&x);
		v[x%m].push_back(x);
	}
	for(i=0;i<m;i++)
	{
		if(v[i].size()>=k)
		{
			printf("Yes\n");
			for(x=0;x<k;x++) printf("%i ",v[i][x]);
			return 0;
		}
	}
	printf("No\n");
	return 0;
}