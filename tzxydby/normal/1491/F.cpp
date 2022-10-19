#include<bits/stdc++.h>
using namespace std;
int ask(int l,int r)
{
	printf("? %d %d\n",l,1);
	for(int x=1;x<=l;x++)
		printf("%d ",x);
	puts("");
	printf("%d\n",r);
	fflush(stdout);
	int s;
	scanf("%d",&s);
	return s;
}
void sol()
{
	int n,x=2;
	scanf("%d",&n);
	vector<int>ans;
	for(int i=2;i<=n;i++)
	{
		if(ask(i-1,i))
		{
			x=i;
			break;
		}
	}
	int l=0,r=x-1;
	while(r-l>1)
	{
		int m=l+r>>1;
		if(ask(m,x))
			r=m;
		else
			l=m;
	}
	for(int i=1;i<x;i++)
		if(i!=r)
			ans.push_back(i);
	for(int i=x+1;i<=n;i++)
	{
		printf("? %d %d\n",1,1);
		printf("%d\n%d\n",x,i);
		fflush(stdout);
		int s;
		scanf("%d",&s);
		if(!s)
			ans.push_back(i);
	}
	printf("! %d ",ans.size());
	for(auto i:ans)
		printf("%d ",i);
	puts("");
	fflush(stdout);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();	
	return 0;
}