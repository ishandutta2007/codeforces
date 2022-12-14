#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#define pii pair<int,int>
using namespace std;
struct node
{
	int num,ide;
	friend bool operator <(node x,node y)
	{
		return x.num<y.num;
	}
}a[200005];
int b[200005],tot;
queue<pii>q;
int main ()
{
	int n,m,d; scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].num),a[i].ide=i;
	sort(a+1,a+1+n);
	b[a[1].ide]=++tot; q.push(make_pair(a[1].num,b[a[1].ide]));
	for(int i=2;i<=n;i++)
	{
		pii tmp=q.front();
		if(a[i].num-tmp.first>d)
		{
			q.pop(); b[a[i].ide]=tmp.second;
			q.push(make_pair(a[i].num,b[a[i].ide]));
		}
		else
		{
			b[a[i].ide]=++tot;
			q.push(make_pair(a[i].num,b[a[i].ide]));
		}
	}
	printf("%d\n",tot);
	for(int i=1;i<=n;i++) printf("%d ",b[i]);
	printf("\n");
	return 0;
}