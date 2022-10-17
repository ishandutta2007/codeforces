#include<stdio.h>
#include<string.h>
int n,f[2020],g[2020];
long long z;
char s[2020];
void ck(int x,int y)
{
	for(;0<=x&&y<n;x--,y++)
		if(s[x]==s[y])
			g[x]++,f[y]++;
		else
			break;
}
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)
		ck(i,i);
	for(int i=1;i<n;i++)
		ck(i-1,i);
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			z+=f[i]*g[j];
	printf("%I64d\n",z);
	return 0;
}