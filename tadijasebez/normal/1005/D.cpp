#include <stdio.h>
#include <cstring>
const int N=200050;
char s[N];
int a[N];
bool use[N];
int main()
{
	int n,i,sol=0;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++) a[i]=(s[i]-'0')%3;
	for(i=1;i<=n;i++)
	{
		if(a[i]==0) sol++,use[i]=1;
		else if(i>1)
		{
			if(!use[i-1] && (a[i]+a[i-1])%3==0)
			{
				sol++;use[i]=use[i-1]=1;
			}
			else if(!use[i-1] && !use[i-2] && (a[i]+a[i-1]+a[i-2])%3==0)
			{
				sol++;use[i]=use[i-1]=use[i-2]=1;
			}
		}
	}
	printf("%i\n",sol);
	return 0;
}