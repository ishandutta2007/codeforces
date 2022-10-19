#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int gre[200005],a[200005];
int main()
{
	int n,sl=0,q,x,sl2=0,sl4=0,sl6=0,sl8=0;
	n=read();
	sl=n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		gre[a[i]]++;
		if(gre[a[i]]==2)sl2++;
		if(gre[a[i]]==4)sl4++;
		if(gre[a[i]]==6)sl6++;
		if(gre[a[i]]==8)sl8++;
	}
	q=read();
	char op[100];
	for(int i=1;i<=q;i++)
	{
		scanf("%s",op+1);
		if(op[1]=='+')
		{
			x=read();
			gre[x]++;
		    sl++;
		    if(gre[x]==2)sl2++;
		    if(gre[x]==4)sl4++;
		    if(gre[x]==6)sl6++;
		    if(gre[x]==8)sl8++;
		    if(sl8>=1||(sl6>=1&&sl2>=2)||(sl4>=1&&sl2>=3)||(sl4>=2))printf("YES\n");
		    else printf("NO\n");
		}
		else
		{
			x=read();
			gre[x]--;
			if(gre[x]==1)sl2--;
		    if(gre[x]==3)sl4--;
		    if(gre[x]==5)sl6--;
		    if(gre[x]==7)sl8--;
		    sl--;
		    if(sl8>=1||(sl6>=1&&sl2>=2)||(sl4>=1&&sl2>=3)||(sl4>=2))printf("YES\n");
		    else printf("NO\n");
		}
	}
	return 0;
}