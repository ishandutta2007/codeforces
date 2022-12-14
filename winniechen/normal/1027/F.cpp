#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define N 2000005
vector<int>v[N];
int fa[N],siz[N],b[N],a[N],c[N],n,val[N],cnt,tot,ans;
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void uni(int x,int y){x=find(x),y=find(y);if(x!=y)fa[y]=x,siz[x]+=siz[y];siz[x]++;}
int main()
{
	scanf("%d",&n);for(int i=1;i<N;i++)fa[i]=i;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]),c[++cnt]=a[i],c[++cnt]=b[i];
	sort(c+1,c+cnt+1);cnt=unique(c+1,c+cnt+1)-c-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(c+1,c+cnt+1,a[i])-c,b[i]=lower_bound(c+1,c+cnt+1,b[i])-c;
	for(int i=1;i<=n;i++)uni(a[i],b[i]);
	for(int i=1;i<=cnt;i++)v[find(i)].push_back(i);
	for(int i=1;i<=cnt;i++)
	{
		if(i==find(i))
		{
			if(siz[i]>v[i].size()){puts("-1");return 0;}
			ans=max(ans,c[v[i][siz[i]-1]]);
		}
	}printf("%d\n",ans);return 0;
}