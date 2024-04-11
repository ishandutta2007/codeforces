#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define N 300005
struct node
{
	int ch[2],flag,num;
}a[N*30];
int b[N],c[N];
int ans[N],cnt=1,n;
void insert(int x)
{
	int now=1;
	for(int i=30;i>=0;i--)
	{
		int t=(c[x]>>i)&1;
		if(!a[now].ch[t])
		{
			a[now].ch[t]=++cnt;
		}
		a[now].num++;
		now=a[now].ch[t];
	}
	a[now].num++;
	a[now].flag=x;
	return ;
}
int find(int x)
{
	int now=1;
	for(int i=30;i>=0;i--)
	{
		ans[x]=ans[x]<<1;
		int t=(b[x]>>i)&1;
		if(a[now].ch[t]&&a[a[now].ch[t]].num)
		{
			now=a[now].ch[t];
		}else
		{
			ans[x]++;
			now=a[now].ch[1-t];
		}
	}
	return a[now].flag;
}
void del(int x)
{
	int now=1;
	for(int i=30;i>=0;i--)
	{
		int t=(c[x]>>i)&1;
		if(a[a[now].ch[t]].num==1)a[now].ch[t]=0;
		now=a[now].ch[t];
		a[now].num--;
	}
	return ;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&c[i]);
		insert(i);
	}
	for(int i=1;i<=n;i++)
	{
		int j=find(i);
		del(j);
	}
	for(int i=1;i<n;i++)printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
	return 0;
}