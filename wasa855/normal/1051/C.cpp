#include<bits/stdc++.h>
using namespace std;
int a[105];
int sum[105];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[a[i]]++;
	}
	int x=0,y=0;
	for(int i=1;i<=100;i++)
	{
		if(sum[i]==1)
		{
			x++;
		}
		if(sum[i]>2)
		{
			y++;
		}
	}
	if((x%2==0)||(x%2==1&&y>0))
	{
		cout<<"YES\n";
		if(x%2==0)
		{
			int cnt=x/2;
			for(int i=1;i<=n;i++)
			{
				if(sum[a[i]]==1&&cnt>0)
				{
					cout<<"A";
					cnt--;
				}
				else
				{
					cout<<"B";
				}
			}
		}
		else
		{
			int cnt=x/2,cc=1;
			for(int i=1;i<=n;i++)
			{
				if(sum[a[i]]==1&&cnt>0)
				{
					cout<<"A";
					cnt--;
				}
				else if(sum[a[i]]>2&&cc>0)
				{
					cout<<"A";
					cc--;
				}
				else
				{
					cout<<"B";
				}
			}
		}
	}
	else
	{
		cout<<"NO\n";
	}
	return 0;
}