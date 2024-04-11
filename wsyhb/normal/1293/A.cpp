#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N],b[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,s,k;
		scanf("%d%d%d",&n,&s,&k);
		memset(a,0,sizeof(a));
		while(k--)
		{
			int x;
			scanf("%d",&x);
			int c=abs(x-s);
			if(c<=1000) a[c]++;
		}
        memset(b,0,sizeof(b));
		b[0]=1;
		for(int i=1;i<=1000;i++)
		{
			if(s-i>0) b[i]++;
			if(s+i<=n) b[i]++;
		}
		for(int i=0;i<=1000;i++)
			if(a[i]<b[i])
			{
				printf("%d\n",i);
				break;
			}
	}
	return 0;
}