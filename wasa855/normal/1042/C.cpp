#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool used[200005];
int main()
{
	int n;
	cin>>n;
	int neg=0;
	int zero=0;
	int pos=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)
		{
			zero++;
			used[i]=true;
		}
		if(a[i]<0)
		{
			neg++;
			if(pos==0)
			{
				pos=i;
			}
			if(abs(a[i])<abs(a[pos]))
			{
				pos=i;
			}
		}
	}
	if(neg%2==1)
	{
		used[pos]=true;
	}
	if(zero==n||(zero==n-1&&neg==1))
	{
		for(int i=1;i<n;i++)
		{
			printf("1 %d %d\n",i,i+1);
		}
		return 0;
	}
	int lst=0;
	for(int i=1;i<=n;i++)
	{
		if(used[i]==true)
		{
			if(lst==0)
			{
				lst=i;
				continue;
			}
			printf("1 %d %d\n",lst,i);
			lst=i;
		}
	}
	if(lst!=0)
	{
		printf("2 %d \n",lst);
	}
	lst=0;
	for(int i=1;i<=n;i++)
	{
		if(used[i]==false)
		{
			if(lst==0)
			{
				lst=i;
				continue;
			}
			printf("1 %d %d\n",lst,i);
			lst=i;
		}
	}
	return 0;
}