#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#define p 1000000007
using namespace std;
int f[5020][5020];
int s[5020][5020];
char a[5020];
char b[5020];
int ans;
int la,lb;
int main()
{
	gets(a+1);
	gets(b+1);
	la=strlen(a+1);
	lb=strlen(b+1);
	int i,j;
	for(i=1;i<=la;i++)
	{
		for(j=1;j<=lb;j++)
			if(a[i]==b[j])
				ans=(ans+(f[i][j]=(s[i-1][j-1]+1)%p))%p;
		for(j=1;j<=lb;j++)
			s[i][j]=(s[i][j-1]+f[i][j])%p;
	}
	printf("%d\n",ans);
	return 0;
}