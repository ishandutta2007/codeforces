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
bool clo[100001];
int cl[100001];
int main()
{
    int t,n,s,k,ans1,ans2;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	n=read();
    	s=read();
    	k=read();
    	for(int j=1;j<=k;j++)
    	{
    		cl[j]=read();
    		if(cl[j]-s>=-30000&&cl[j]-s<=30000)clo[cl[j]-s+30000]=1;
		}
		ans1=1;
		while(clo[ans1+30000]==1)ans1++;
		if(ans1>n-s)ans1=1000000000;
		ans2=1;
		while(clo[30000-ans2]==1)ans2++;
		if(ans2>s-1)ans2=1000000000;
		if(!clo[30000])printf("0\n");
		else printf("%d\n",min(ans1,ans2));
		for(int j=1;j<=k;j++)
		{
			if(cl[j]-s>=-30000&&cl[j]-s<=30000)clo[cl[j]-s+30000]=0;
		} 
	}
    return 0;
}