#include<iostream>
#include<cstdio>
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
signed main()
{
	int t,s,n,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		s=read();
		n=read();
		k=read();
		if(k>n)
		{
			if(s<k)printf("NO\n");
			else if(s>=k+1)printf("NO\n");
			else printf("YES\n");
			continue;
		}
		int maxs=(n/k)*(2*k)+(n%k);
		if(s<maxs)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}