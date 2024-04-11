#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=2000005;
int n,p,M,m,nd;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,T,top;
int dfn[N],low[N],sta[N];
int be[N],vis[N],blk;
int L[N],R[N],q[N];
vector<int> veci[N],vecQ[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void tarjan(int x){
	low[x]=dfn[x]=++T;
	vis[x]=1; sta[++top]=x;
	for (int i=head[x];i;i=e[i].next)
		if (!dfn[e[i].to]){
			tarjan(e[i].to);
			low[x]=min(low[x],low[e[i].to]);
		}
		else if (vis[e[i].to])
			low[x]=min(low[x],dfn[e[i].to]);
	if (low[x]==dfn[x]){
		blk++;
		int y=19260817;
		for (;y!=x;){
			y=sta[top--];
			vis[y]=0; be[y]=blk;
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&p,&M,&m);
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x+p,y); add(y+p,x);
	}
	For(i,1,p){
		scanf("%d%d",&L[i],&R[i]);
		veci[R[i]].PB(i);
		vecQ[L[i]].PB(i);
	}
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y+p); add(y,x+p);
	}
	nd=p*2;
	int now1=++nd;
	int now2=++nd;
	For(i,1,M){
		For(j,0,vecQ[i].size()-1){
			add(vecQ[i][j],now1);
			add(now2,vecQ[i][j]+p);
		}
		For(j,0,veci[i].size()-1){
			++nd;
			add(nd,now1);
			add(nd,veci[i][j]+p);
			now1=nd;
			++nd;
			add(now2,nd);
			add(veci[i][j],nd);
			now2=nd;
		}
	}
	For(i,1,2*p)
		if (!dfn[i])
			tarjan(i);
	For(i,1,p)
		if (be[i]==be[i+p])
			return puts("-1"),0;
	int l=1,r=M;
	For(i,1,p)
		if (be[i]<be[i+p]){
			q[++*q]=i;
			l=max(l,L[i]);
			r=min(r,R[i]);
		}
	printf("%d %d\n",*q,l);
	For(i,1,*q) printf("%d ",q[i]);
}