#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Data
{
	int a,b;
	int id;
}a[300005],b[300005];
int n,num1,num2;
bool cmp1(Data x,Data y)
{
	return x.a>y.a;
}
bool cmp2(Data x,Data y)
{
	return x.a<y.a;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x<y)
		{
			a[++num1].a=x,a[num1].b=y;
			a[num1].id=i;
		}
		else
		{
			b[++num2].a=x,b[num2].b=y;
			b[num2].id=i;
		}
	}
	printf("%d\n",max(num1,num2));
	sort(a+1,a+num1+1,cmp1);
	sort(b+1,b+num2+1,cmp2);
	if(num1<=num2)
	{
		for(int i=1;i<=num2;i++)printf("%d ",b[i].id);
		printf("\n");
	}
	else
	{
		for(int i=1;i<=num1;i++)printf("%d ",a[i].id);
		printf("\n");
	}
	return 0;
}