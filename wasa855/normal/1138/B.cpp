#include<bits/stdc++.h>
using namespace std;
int s1[5005],s2[5005];
int main()
{
	int A=0,B=0,C=0,D=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%1d",&s1[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%1d",&s2[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(s1[i]==0&&s2[i]==0)
		{
			A++;
		}
		if(s1[i]==0&&s2[i]==1)
		{
			B++;
		}
		if(s1[i]==1&&s2[i]==0)
		{
			C++;
		}
		if(s1[i]==1&&s2[i]==1)
		{
			D++;
		}
	}
	int a,b,c,d;
	int sa=0,sb=0,sc=0,sd=0;
	for(a=0;a<=A;a++)
	{
		d=B+D+a-n/2;
		if(d<=D&&d>=0)
		{
			for(b=0;b<=B;b++)
			{
				c=n/2-a-d-b;
				if(c<=C&&c>=0)
				{
					if(a+b+c+d==n/2)
					{
						for(int i=1;i<=n;i++)
						{
							if(s1[i]==0&&s2[i]==0)
							{
								if(a>sa)
								{
									sa++;
									printf("%d ",i);
								}
							}
							if(s1[i]==0&&s2[i]==1)
							{
								if(b>sb)
								{
									sb++;
									printf("%d ",i);
								}
							}
							if(s1[i]==1&&s2[i]==0)
							{
								if(c>sc)
								{
									sc++;
									printf("%d ",i);
								}
							}
							if(s1[i]==1&&s2[i]==1)
							{
								if(d>sd)
								{
									sd++;
									printf("%d ",i);
								}
							}
						}
						return 0;
					}
				}
			}
		}
	}
	cout<<"-1\n";
	return 0;
}