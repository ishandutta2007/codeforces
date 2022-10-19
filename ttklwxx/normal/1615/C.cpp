#include<iostream>
#include<cstdio>
#include<cstring>
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
char a[200005],b[200005];
int cy[200005];
int main()
{
	int t,n,l,r,ans=0,sl1,sl2,sl3,sl4;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		scanf("%s",a+1);
		scanf("%s",b+1);
		sl1=0;
		sl2=0;
		sl3=sl4=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='0'&&b[i]=='0')sl1++;
			if(a[i]=='0'&&b[i]=='1')sl2++;
			if(a[i]=='1'&&b[i]=='0')sl3++;
			if(a[i]=='1'&&b[i]=='1')sl4++; 
		}
		ans=1000000000;
		if(sl3-sl2==0)ans=min(ans,sl3+sl2);
		if(sl4-sl1==1)ans=min(ans,sl4+sl1);
		if(ans<1000000000)printf("%d\n",ans);
		else printf("-1\n");
	}
	return 0;
}