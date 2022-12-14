#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
struct node{int to,next;}e[N<<1];
struct edge{int x,y,z;}a[N],ans[N<<5];
int d[N],n,head[N],cnt,tot;
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;d[x]++;}
void dfs(int x,int from,int &p)
{
	if(d[x]==1&&!p)p=x;
	for(int i=head[x];i!=-1;i=e[i].next)if(e[i].to!=from)dfs(e[i].to,x,p);
}
int main()
{
	scanf("%d",&n);memset(head,-1,sizeof(head));
	for(int i=1,x,y,z;i<n;i++)scanf("%d%d%d",&x,&y,&z),a[i]=(edge){x,y,z},add(x,y),add(y,x);
	for(int i=1;i<=n;i++)if(d[i]==2)return puts("NO"),0;
	puts("YES");
	for(int i=1;i<n;i++)
	{
		int x=a[i].x,y=a[i].y,z=a[i].z,p1=0,p2=0,p3=0,p4=0;
		if(d[x]==1)p1=p2=x;
		else 
		{
			for(int j=head[x];j!=-1;j=e[j].next)
				if(e[j].to!=y)
				{
					if(!p1)dfs(e[j].to,x,p1);
					else if(!p2)dfs(e[j].to,x,p2);
				}
		}
		if(d[y]==1)p3=p4=y;
		else 
		{
			for(int j=head[y];j!=-1;j=e[j].next)
				if(e[j].to!=x)
				{
					if(!p3)dfs(e[j].to,y,p3);
					else if(!p4)dfs(e[j].to,y,p4);
				}
		}
		ans[++tot]=(edge){p1,p3,z>>1},ans[++tot]=(edge){p2,p4,z>>1};
		if(p1!=p2)ans[++tot]=(edge){p1,p2,-(z>>1)};if(p3!=p4)ans[++tot]=(edge){p3,p4,-(z>>1)};
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].z);
}