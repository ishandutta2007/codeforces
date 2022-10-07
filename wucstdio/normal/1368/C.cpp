#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	printf("%d\n",n*3+4);
	for(int i=1;i<=n+2;i++)printf("%d %d\n",i,i);
	for(int i=1;i<=n+1;i++)printf("%d %d\n",i,i+1);
	for(int i=1;i<=n+1;i++)printf("%d %d\n",i+1,i);
	return 0;
}