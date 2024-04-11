#include <bits/stdc++.h>
using namespace std;
int n,num[105],cnt[105],all,oth,a,b,belong[105],flag,it;
bool tag[105],FLAG;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		cnt[num[i]]++;
	}
	for(int i=1;i<=100;i++)
	{
		if(cnt[i]==1) all++,tag[i]=true;
		else if(cnt[i]!=2&&cnt[i]) oth++;
	}
	if(all%2&&oth) 
	{
		printf("YES\n");
		for(int i=1;i<=100;i++)
		{
			if(tag[i])
			{
				if(a>b)
					belong[i]=2,b++;
				else belong[i]=1,a++;
			}
			else if(cnt[i]!=2&&cnt[i]&&!flag)
			{
				if(a>b)
					belong[i]=2,b++;
				else belong[i]=1,a++;
				flag=i;
			}
			else if(cnt[i])
				belong[i]=a;
		}
		for(int i=1;i<=n;i++)
		{
			if(flag!=num[i])
				printf("%c",belong[num[i]]==2?'B':'A');
			else if(!FLAG)
			{
				FLAG=true;
				printf("%c",belong[num[i]]==2?'B':'A');
			}
			else
				printf("%c",belong[num[i]]==2?'A':'B');
			}
	}
	else if(all%2==0)
	{
		printf("YES\n");
		for(int i=1;i<=100;i++)
		{
			if(tag[i])
			{
				if(a>b)
					belong[i]=2,b++;
				else belong[i]=1,a++;
			}
		}
		for(int i=1;i<=n;i++) printf("%c",belong[num[i]]==1?'A':'B');
	}
	else printf("NO");
	return 0;
}