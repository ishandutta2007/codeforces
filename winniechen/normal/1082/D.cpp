#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
#include <stack>
using namespace std;
#define N 505
#define ll long long
struct node
{
	int x,idx;
	bool operator < (const node &a) const {return x>a.x;}
}a[N];
int d[N],n,map[N][N],dep[N],num;
stack<node>q;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].x),a[i].idx=i;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)if(a[i].x==1)q.push(a[i]),dep[a[i].idx]=1,num++;
	if(num==0)
	{
		printf("YES %d\n",n-1);
		printf("%d\n",n-1);
		for(int i=1;i<n;i++)printf("%d %d\n",i,i+1);
		return 0;
	}else if(num==1)
	{
		printf("YES %d\n",n-1);
		printf("%d\n",n-1);
		for(int i=1;i<n-1;i++)printf("%d %d\n",a[i].idx,a[i+1].idx);
		printf("%d %d\n",a[1].idx,a[n].idx);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(dep[a[i].idx])continue;
		int t=0;
		while(a[i].x>1&&q.size()>1)
		{
			int x=q.top().idx;q.pop();dep[a[i].idx]=max(dep[a[i].idx],dep[x]+1);
			map[x][a[i].idx]=1;a[i].x--;
		}
		if(q.size()==1&&a[i+1].x==1)map[q.top().idx][a[i].idx]=1,q.pop();
		else q.push(a[i]);
	}
	if(!q.empty())return puts("NO"),0;
	int ans=0;
	for(int i=1;i<=n;i++)ans=max(ans,dep[i]);
	printf("YES %d\n%d\n",ans,n-1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)if(map[i][j])
			printf("%d %d\n",i,j);
}