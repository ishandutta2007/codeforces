#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
using namespace std;
#define N 45005
int n,s1[N],s2[N],ans1,ans2,num[N],sum;
int check(int x)
{
	if((sum-x)>0&&sum%x==0)
	{
		puts("Yes");
		printf("%d %d\n%d ",1,x,n-1);
		for(int i=1;i<=n;i++)if(i!=x)printf("%d ",i);puts("");exit(0);
	}
}
int main()
{
	scanf("%d",&n);if(n<=2){puts("No");return 0;}sum=((n+1)*n)>>1;
	for(int i=2;i<=n;i++)check(i);puts("No");return 0;
}