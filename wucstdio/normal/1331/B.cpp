#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		if(n%i==0)
		{
			printf("%d%d\n",i,n/i);
			return 0;
		}
	}
	return 0;
}