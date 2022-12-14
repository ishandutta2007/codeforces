#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
#define ll long long
int n,m,id[N],siz[N],sum[N],vis[N];
vector<int >v[N];
inline bool cmp(const int &a,const int &b){return siz[a]<siz[b];}
inline bool cmp1(const int &a,const int &b){return a>b;}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=n;i++)scanf("%d%d",&x,&y),v[x].push_back(y);
	for(int i=1;i<=m;i++)
		sort(v[i].begin(),v[i].end(),cmp1),id[i]=i,siz[i]=v[i].size();
	sort(id+1,id+m+1,cmp);
	int pos=1,mx=0,ret=0;
	for(int i=1;i<=n;i++)
	{
		while((vis[id[pos]]||siz[id[pos]]<i)&&pos<=m)
			ret-=sum[id[pos]],pos++;
		for(int j=pos;j<=m;j++)
		{
			if(!vis[id[j]])
			{
				ret+=v[id[j]][i-1],sum[id[j]]+=v[id[j]][i-1];
				if(sum[id[j]]<0)ret-=sum[id[j]],vis[id[j]]=1,sum[id[j]]=0;
			}
		}
		mx=max(mx,ret);
	}
	printf("%d\n",mx);
}