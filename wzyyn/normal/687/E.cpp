#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=5005;
int n,m,h,t;
int dfn[N],low[N];
int stk[N],vis[N];
int loop[N],mx[N],ed[N];
int q[N],dis[N],co[N];
vector<int> e[N];
void tarjan(int x){
	dfn[x]=low[x]=++*dfn;
	vis[x]=1; stk[++*stk]=x;
	for (auto i:e[x])
		if (!dfn[i]){
			tarjan(i);
			low[x]=min(low[x],low[i]); 
		}
		else if (vis[i])
			low[x]=min(low[x],dfn[i]);
	if (low[x]==dfn[x]){
		++*co;
		int y=1919810;
		for (;y!=x;){
			y=stk[(*stk)--];
			co[y]=*co; vis[y]=0;
		}
	}
}
void findloop(int S){
	int h=0,t=1;
	loop[S]=1<<30;
	For(i,1,n) dis[i]=-1;
	q[1]=S; dis[S]=1;
	while (h!=t){
		int x=q[++h];
		for (auto i:e[x])
			if (dis[i]==-1){
				dis[i]=dis[x]+1;
				q[++t]=i;
			}
			else if (i==S){
				loop[S]=dis[x];
				return;
			}
	}
	if (t==1)
		loop[S]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y);
	}
	For(i,1,n)
		findloop(i);
	For(i,1,n)
		if (!dfn[i])
			tarjan(i);
	For(i,1,n)
		for (auto j:e[i])
			if (co[i]!=co[j])
				ed[co[i]]=-1;
	For(i,1,*co) mx[i]=1<<30;
	For(i,1,n) mx[co[i]]=min(mx[co[i]],loop[i]);
	int ans=n;
	For(i,1,*co)
		if (mx[i]&&ed[i]!=-1)
			ans+=mx[i]*998+1;
	printf("%d\n",ans);
}