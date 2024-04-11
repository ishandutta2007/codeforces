#include<stdio.h>
#include<string.h>
int p[10020][26];
char s1[10020];
char s2[1000020];
int n,m,z,r;
int main()
{
	scanf("%s %s",s1+1,s2);
	n=strlen(s1+1),m=strlen(s2);
	for(int i=0;i<26;i++)
		p[n][i]=-1;
	for(int i=n-1;i>=0;i--)
	{
		memcpy(p[i],p[i+1],sizeof p[0]);
		p[i][s1[i+1]-'a']=i+1;
	}
	for(int i=0;i<m;i++)
		if(p[0][s2[i]-'a']==-1)
			return puts("-1"),0;
	for(int i=0;i<m;i++)
	{
		if(p[r][s2[i]-'a']==-1)
			r=0,z++;
		r=p[r][s2[i]-'a'];
	}
	printf("%d",z+1);
	return 0;
}