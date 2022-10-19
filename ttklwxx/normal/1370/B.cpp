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
int a[200001],os[200001],oc,js[200001],jc;
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		oc=0;
		jc=0;
		for(int i=1;i<=2*n;i++)
		{
			a[i]=read();
			if(a[i]%2==0)os[++oc]=i;
			else js[++jc]=i;
		}
		if(oc==2*n)
		{
			for(int i=1;i<=n-1;i++)printf("%d %d\n",2*i-1,2*i);
			continue;
		}
		for(int i=1;i<=oc/2;i++)printf("%d %d\n",os[2*i-1],os[2*i]);
		if(jc%2==0)for(int i=1;i<=jc/2-1;i++)printf("%d %d\n",js[2*i-1],js[2*i]);
		else for(int i=1;i<=jc/2;i++)printf("%d %d\n",js[2*i-1],js[2*i]);
	} 
	return 0;
}