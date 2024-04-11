#include <bits/stdc++.h>
using namespace std;
const int N = 300005 , M = 500005;
struct node{int to,next;}e[M<<1];
int head[N],cnt,n,m,a[N],c[M];
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
void solve()
{
	scanf("%d%d",&n,&m);memset(head,-1,sizeof(int)*(n*3+3));cnt=0;
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);
	memset(a,0,sizeof(int)*(n*3+3));memset(c,0,sizeof(int)*(m+3));
	for(int x=1;x<=n*3;x++)
	{
		a[x] = 1;
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			int to1=e[i].to;
			if(a[to1]){a[x]=a[to1]=0,c[(i>>1)+1]=1;break;}
		}
	}
	int cnt=0;
	for(int i=1;i<=n*3;i++)cnt+=a[i];
	if(cnt>=n)
	{
		puts("IndSet");
		for(int i=1,lim=n;i<=n*3&&lim;i++)if(a[i])printf("%d ",i),lim--;puts("");
	}else
	{
		puts("Matching");
		for(int i=1,lim=n;i<=m&&lim;i++)if(c[i])printf("%d ",i),lim--;puts("");
	}
}
int main(){int T;scanf("%d",&T);while(T--)solve();}