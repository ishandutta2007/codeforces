#include<bits/stdc++.h>
using namespace std;
char s[100005];
int main()
{
	int flag=0,last=0,sum=0,sumn=0;
	while(scanf("%s",s)!=EOF)
	{
		int n=strlen(s);
		reverse(s,s+n);
		sum++;
		if(!strncmp(s,"soil",4))
		{
			if(flag==2||last!=0)
			{
				puts("NO");
				return 0;
			}
			flag=1;
			last=0;
		}
		else if(!strncmp(s,"alail",5))
		{
			if(flag==1||last!=0)
			{
				puts("NO");
				return 0;
			}
			flag=2;
			last=0;
		}
		else if(!strncmp(s,"rte",3))
		{
			if(flag==2||last!=0)
			{
				puts("NO");
				return 0;
			}
			flag=1;
			last=1;
			sumn++;
		}
		else if(!strncmp(s,"arte",4))
		{
			if(flag==1||last!=0)
			{
				puts("NO");
				return 0;
			}
			flag=2;
			last=1;
			sumn++;
		}
		else if(!strncmp(s,"sitini",6))
		{
			if(flag==2||(last==0&&flag))
			{
				puts("NO");
				return 0;
			}
			flag=1;
			last=2;
		}
		else if(!strncmp(s,"setini",6))
		{
			if(flag==1||(last==0&&flag))
			{
				puts("NO");
				return 0;
			}
			flag=2;
			last=2;
		}
		else
		{
			puts("NO");
			return 0;
		}
	}
	if(sum!=1&&sumn==0)
		puts("NO");
	else
		puts("YES");
	return 0;
}
//