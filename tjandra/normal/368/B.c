#include<stdio.h>
typedef unsigned u;
char M[100001];
u m[100001],s[100001];
int main()
{
	u n,k,i;
	scanf("%u%u",&n,&k);
	for(i=0;i<n;scanf("%u",m+i++));
	for(i=n;i--;)
	{
		s[i]=s[i+1];
		if(!M[m[i]]){M[m[i]]=1;s[i]++;}
	}
	while(k--)
	{
		scanf("%u",&n);
		printf("%u\n",s[n-1]);
	}
	return 0;
}