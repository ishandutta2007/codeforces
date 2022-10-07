#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
void work(int x,int k)
{
	if(x==1)
	{
		printf("%d\n",k);
		return;
	}
	if(x==2)
	{
		printf("%d %d\n",k,2*k);
		return;
	}
	if(x==3)
	{
		printf("%d %d %d\n",k,k,3*k);
		return;
	}
	for(int i=1;i<=x-x/2;i++)
	  printf("%d ",k);
	work(x/2,k*2);
}
int main()
{
	scanf("%d",&n);
	work(n,1);
//	main();
	return 0;
}