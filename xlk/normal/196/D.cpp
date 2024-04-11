#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char s[400020];
char z[400020];
int p[400020];
int f[400020];
int g[400020];
int d,l,w=1000000007;
int ok(int y,int l)
{
	int x=y-l;
	if(x<0)
		return 1;
	return (g[y]-g[x]*p[l])*p[x+1]!=f[y]-f[x];
}
void dfs(int x,int y)
{
	if(x>l)
	{
		puts(z+1);
		exit(0);
	}
	for(char i=y?'a':s[x];i<='z';i++)
	{
		z[x]=i,f[x]=f[x-1]+i*p[x],g[x]=g[x-1]*w+i;
		if(x==3)
			x=3;
		if(ok(x,d)&&ok(x,d+1))
			dfs(x+1,y||i>s[x]);
	}
}
int main()
{
	scanf("%d%s",&d,s+1);
	l=strlen(s+1);
	for(int i=p[0]=1;i<=l;i++)
		p[i]=p[i-1]*w;
	for(int i=l;i;i--)
		if(s[i]=='z')
			s[i]='a';
		else
		{
			s[i]++;
			goto _;
		}
	__:
	return puts("Impossible"),0;
	_:
	dfs(1,0);
	goto __;
}