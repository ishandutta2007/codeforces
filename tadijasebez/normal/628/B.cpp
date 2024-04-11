#include <stdio.h>
#include <cstring>
#define ll long long
const int N=300050;
char s[N];
ll sol;
int main()
{
	int n,i;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
	{
		if((s[i]-'0')%4==0) sol++;
	}
	for(i=2;i<=n;i++)
	{
		if(((s[i-1]-'0')*10+s[i]-'0')%4==0) sol+=i-1;
	}
	printf("%lld\n",sol);
	return 0;
}