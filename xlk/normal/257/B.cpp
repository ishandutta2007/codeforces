#include <stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	int z=min(n,m),y=n+m-z-1;
	printf("%d %d\n",y,z);
	return 0;
}