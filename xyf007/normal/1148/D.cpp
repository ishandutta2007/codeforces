#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
struct node
{
	int a,b,ind;
}a[300001],a1[300001],a2[300001];
int n,temp1,temp2;
std::vector<int>ans1,ans2;
bool cmp1(node x,node y)
{
	return x.a>y.a;
}
bool cmp2(node x,node y)
{
	return x.b<y.b;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		a[i].ind=i;
		scanf("%d%d",&a[i].a,&a[i].b);
		if(a[i].a<a[i].b)
		{
			a1[++temp1]=a[i];
		}
		else
		{
			a2[++temp2]=a[i];
		}
	}
	if(temp1)
	{
		std::sort(a1+1,a1+temp1+1,cmp1);
		for(int i=1;i<=temp1;i++)
		{
			ans1.push_back(a1[i].ind);
		}
	}
	if(temp2)
	{
		std::sort(a2+1,a2+temp2+1,cmp2);
		for(int i=1;i<=temp2;i++)
		{
			ans2.push_back(a2[i].ind);
		}
	}
	if(temp1>temp2)
	{
		printf("%d\n",temp1);
		for(std::vector<int>::iterator it=ans1.begin();it!=ans1.end();it++)
		{
			printf("%d ",*it);
		}
	}
	else
	{
		printf("%d\n",temp2);
		for(std::vector<int>::iterator it=ans2.begin();it!=ans2.end();it++)
		{
			printf("%d ",*it);
		}
	}
	return 0;
}//