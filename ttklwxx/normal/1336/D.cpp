#include<iostream>
#include<cstdio>
#include<cmath>
#define int long long
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
int ansk[200005],anss[200005];
int a[200005];
int n;
signed main()
{
	int ans1k,ans1s,pk=0,ps=0;
	n=read();
	pk=read();
	ps=read();
	for(int i=n-1;i>=3;i--)
	{
		printf("+ %d\n",i);
		fflush(stdout);
		ansk[i]=read()-pk;
		anss[i]=read()-ps;
		pk=ansk[i]+pk;
		ps=anss[i]+ps; 
	}
	for(int i=1;i<=2;i++)
	{
		printf("+ %d\n",i);
		fflush(stdout);
		ansk[i]=read()-pk;
		anss[i]=read()-ps;
		pk=ansk[i]+pk;
		ps=anss[i]+ps;
	}
	printf("+ 1\n");
	fflush(stdout);
	ans1k=read()-pk;
	ans1s=read()-ps;
	a[1]=(sqrt(8*(ans1k)+1)-1)/2;
	a[3]=ans1s-anss[1]-1;
	a[2]=ans1s/(a[3]+1)-1;
	a[4]=(anss[2]-(a[1]+1)*(a[3]+1))/(a[3]+1);
	if(n!=4)a[4]--;
	for(int i=5;i<=n;i++)
	{
		a[i]=(anss[i-2]-a[i-4]*a[i-3]-(a[i-1]+1)*a[i-3])/(a[i-1]+1);
		if(i!=n)a[i]--;
	}
	printf("! ");	
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}