#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[2000005],ss[2000005];
int t,n,f[2000005];
void manacher()
{
	for(int i=n*2;i>1;i--)
	{
		if(i&1)s[i]='@';
		else s[i]=s[i>>1];
	}
	s[1]=s[2*n+1]='#';
	n=2*n+1;
	f[1]=1;
	int nowmid=1,nowright=1;
	for(int i=2;i<=n;i++)
	{
		if(i<=nowright)
		{
			int p=nowmid*2-i;
			f[i]=min(f[p],nowright-i+1);
		}
		else f[i]=1;
		while(i+f[i]<=n&&i-f[i]>=1&&s[i+f[i]]==s[i-f[i]])f[i]++;
		if(nowright<i+f[i]-1)
		{
			nowright=i+f[i]-1;
			nowmid=i;
		}
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",ss+1);
		n=(int)strlen(ss+1);
		int m=n;
		int l=1;
		while(l<=n/2&&ss[l]==ss[n-l+1])l++;
		if(l*2>n)
		{
			printf("%s\n",ss+1);
			continue;
		}
		for(int i=1;i<=n-2*(l-1);i++)
		  s[i]=ss[l+i-1];
		n-=2*(l-1);
		s[n+1]='\0';
		manacher();
		int pos=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]==i-1&&f[i]>f[pos])pos=i;
			if(f[i]==n-i&&f[i]>f[pos])pos=i;
		}
		for(int i=1;i<l;i++)putchar(ss[i]);
		for(int i=pos-f[pos]+1;i<=pos+f[pos]-1;i++)
		  if(s[i]>='a'&&s[i]<='z')putchar(s[i]);
		for(int i=m-l+2;i<=m;i++)putchar(ss[i]);
		putchar('\n');
	}
	return 0;
}