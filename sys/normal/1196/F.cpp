#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int n,m,k,mapping[Maxn],node[Maxn],ct,c,cnt,head[Maxn];
long long ans[Maxn],mini[805][805];
struct edg
{
	int nxt,to,w;
}edge[2*Maxn];
void add(int x,int y,int w)
{
	edge[++cnt]=(edg){head[x],y,w};
	head[x]=cnt;
}
struct EDGE
{
	int x,y,w;
	bool operator < (const EDGE &tmp) const
	{
		return w<tmp.w;
	}
}E[Maxn];
int main()
{
//	freopen("F.in","r",stdin);
	memset(mini,0x3f,sizeof(mini));
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&E[i].x,&E[i].y,&E[i].w);
	sort(E+1,E+1+m);
	for(int i=1;i<=k;i++)
		node[++ct]=E[i].x,node[++ct]=E[i].y;
	sort(node+1,node+1+ct);
	ct=unique(node+1,node+1+ct)-node-1;
	for(int i=1;i<=ct;i++)
		mapping[node[i]]=i;
	for(int i=1;i<=k;i++)
		mini[mapping[E[i].x]][mapping[E[i].y]]=mini[mapping[E[i].y]][mapping[E[i].x]]=E[i].w;
	for(int k=1;k<=ct;k++)
		for(int i=1;i<=ct;i++)
			for(int j=1;j<=ct;j++)
				mini[i][j]=min(mini[i][j],mini[i][k]+mini[k][j]);
	for(int i=1;i<=ct;i++)
		for(int j=i+1;j<=ct;j++)
			if(mini[i][j]!=0x3f3f3f3f3f3f3f3f) ans[++c]=mini[i][j];
	sort(ans+1,ans+1+c);
	printf("%lld",ans[k]);
	return 0;
}