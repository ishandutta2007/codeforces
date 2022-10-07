#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	if(m==0)
	{
		printf("1\n");
		return 0;
	}
	m=min(m,n-m);
	printf("%d\n",m);
	return 0;
}