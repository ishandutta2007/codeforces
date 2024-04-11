#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 200005
struct node{int x,y,z;}a[N];
bool cmp(const node &a,const node &b){return a.z>b.z;}
int fa[N],siz[N],num[N],n,m;long long ans;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++)
	{
		int x=a[i].x,y=a[i].y;
		if(find(x)!=find(y))
		{
			siz[find(x)]+=siz[find(y)];
			num[find(x)]+=num[find(y)]+1;
			fa[find(y)]=find(x);
			if(num[find(x)]<=siz[find(x)])ans+=a[i].z;else num[find(x)]=siz[find(x)];
		}else if(num[find(x)]<=siz[find(x)]-1)num[find(x)]++,ans+=a[i].z;
	}
	printf("%lld\n",ans);
}