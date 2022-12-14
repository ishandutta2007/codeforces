#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <iostream>
#include <cstdlib>
using namespace std;
#define N 3005
struct node
{
	int x,idx,rnk,val;
}a[N];
bool cmp(const node &a,const node &b){return a.x<b.x;}
bool cmp1(const node &a,const node &b){return a.idx<b.idx;}
int minn[N],n;
void fix(int x,int c){for(int i=x;i<N;i+=i&-i)minn[i]=min(minn[i],c);}
int find(int x){int ret=1<<30;for(int i=x;i;i-=i&-i)ret=min(ret,minn[i]);return ret;}
int main()
{
	memset(minn,0x3f,sizeof(minn));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].x);a[i].idx=i;
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].val);
	}
	sort(a+1,a+n+1,cmp);int cnt=0;a[0].x=-1<<30;
	for(int i=1;i<=n;i++)
	{
		if(a[i].x!=a[i-1].x)cnt++;
		a[i].rnk=cnt;
	}
	sort(a+1,a+n+1,cmp1);
	fix(a[1].rnk,a[1].val);
	int ans=1<<30;
	for(int i=2;i<n;i++)
	{
		int x=find(a[i].rnk-1);
		fix(a[i].rnk,a[i].val);
		if(x==0x3f3f3f3f)continue;
		int minn=1<<30;
		for(int j=i+1;j<=n;j++)
		{
			if(a[j].x>a[i].x)
			{
				minn=min(minn,a[j].val);
			}
		}
		if(minn==(1<<30))continue;
		//printf("%d\n",minn);
		ans=min(ans,a[i].val+x+minn);
	}
	printf("%d\n",(ans==(1<<30))?-1:ans);
	return 0;
}