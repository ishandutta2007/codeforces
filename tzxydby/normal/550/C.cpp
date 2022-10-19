#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N]; 
char s[N];
int main()
{
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0;i<n;i++)
		a[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++)
	{
		if(a[i]%8==0)
		{
			printf("YES\n%d\n",a[i]);
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
			continue;
		for(int j=i+1;j<=n;j++)
		{
			if((a[i]*10+a[j])%8==0)
			{
				printf("YES\n%d\n",a[i]*10+a[j]);
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!a[i])
			continue;
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if((a[i]*100+a[j]*10+a[k])%8==0)
				{
					printf("YES\n%d\n",a[i]*100+a[j]*10+a[k]);
					return 0;
				}
			}
		}
	}
	printf("NO\n");
	return 0;
}