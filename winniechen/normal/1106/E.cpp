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
#define M 205
#define ll long long
int n,m,K,p[N];ll f[N][M];
struct node{int s,t,d,w;}a[N];
bool cmp(const node &a,const node &b){return a.s==b.s?a.t<b.t:a.s<b.s;}
priority_queue<pair<pair<int ,int > ,int > >q;
int main()
{
	scanf("%d%d%d",&n,&m,&K);memset(f,0x3f,sizeof(f));
	for(int i=1;i<=K;i++)scanf("%d%d%d%d",&a[i].s,&a[i].t,&a[i].d,&a[i].w);sort(a+1,a+K+1,cmp);
	for(int i=1,j=1;i<=n;i++)
	{
		while(a[j].s<=i&&j<=K)q.push(make_pair(make_pair(a[j].w,a[j].d),j)),j++;
		while(!q.empty()&&a[q.top().second].t<i)q.pop();
		if(!q.empty())p[i]=q.top().second;
	}
	f[1][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
		{
			int x=p[i];
			f[i+1][j+1]=min(f[i][j],f[i+1][j+1]);
			if(x)f[a[x].d+1][j]=min(f[i][j]+a[x].w,f[a[x].d+1][j]);
			else f[i+1][j]=min(f[i][j],f[i+1][j]);
		}
	ll ans=1ll<<60;
	for(int i=0;i<=m;i++)ans=min(ans,f[n+1][i]);
	printf("%lld\n",ans);
}