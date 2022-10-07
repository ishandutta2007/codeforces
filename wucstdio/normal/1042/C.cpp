#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,a[200005],minn,num;
bool flag[200005],ff=1;
int main()
{
	scanf("%I64d",&n);
	a[0]=-2147483647;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		if(a[i]<0&&a[i]>a[minn])minn=i;
		if(a[i]<0)num++;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0||minn==i&&(num&1))flag[i]=0;
		else flag[i]=1;
	}
	int last1=1,last2=1;
	while(last1<=n&&flag[last1]==0)last1++;
	while(last2<=n&&flag[last2]==1)last2++;
	if(last1==n+1||last2==n+1)ff=0;
	for(int i=2;i<=n;i++)
	{
		if(i==last1||i==last2)continue;
		if(flag[i]==1)
		{
			printf("1 %d %d\n",last1,i);
			last1=i;
		}
		else
		{
			printf("1 %d %d\n",last2,i);
			last2=i;
		}
	}
	if(ff)printf("2 %d\n",last2);
	return 0;
}