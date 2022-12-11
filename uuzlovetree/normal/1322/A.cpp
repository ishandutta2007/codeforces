#include<bits/stdc++.h>
#define inf 1000000007
using namespace std;
int n; 
char s[1000005];
int eq[1000005],stk[1000005],top;
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='(')eq[i]=eq[i-1]+1;
		else eq[i]=eq[i-1]-1;
	}
	if(eq[n])puts("-1");
	else
	{
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			if(s[i]=='(')stk[++top]=1;
			else
			{
				if(top)
				{
					if(eq[i]>=0)ans+=2;
					top--;
				}
			}
		}
		printf("%d\n",n-ans);
	}
}