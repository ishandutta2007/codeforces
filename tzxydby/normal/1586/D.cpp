#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,p[N];
int ask(int x,int y)
{
	printf("? ");
	for(int i=1;i<n;i++)
		printf("%d ",x);
	printf("%d ",y);
	puts("");
	fflush(stdout);
	int v;
	scanf("%d",&v);
	return v;
}
int main()
{
	scanf("%d",&n);
	p[n]=n;
	for(int i=1;i<n;i++)
	{
		int v=ask(n,n-i);
		if(!v)
		{
			p[n]=i;
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(i==p[n])
			continue;
		int v=ask(p[n],i);
		p[v]=i;
	}
	printf("! ");
	for(int i=1;i<=n;i++)
		printf("%d ",p[i]);
	puts("");
	fflush(stdout);
	return 0;
}