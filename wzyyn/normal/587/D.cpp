#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=300005;
struct edge{
	int to,next;
}e[N*10];
struct EDGE{
	int x,y,c,v;
}E[N*10];
int head[N],tot;
int dfn[N],low[N],nd,co;
int stk[N],vis[N],be[N];
int q[N],n,m,top;
vector<int> vec[N];
bool cmp(int x,int y){
	return E[x].c<E[y].c;
}
void add(int x,int y){
	//printf("%d %d\n",x,y);
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void tarjan(int x){
	low[x]=dfn[x]=++*dfn;
	stk[++*stk]=x; vis[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (!dfn[e[i].to]){
			tarjan(e[i].to);
			low[x]=min(low[x],low[e[i].to]);
		}
		else if (vis[e[i].to])
			low[x]=min(low[x],dfn[e[i].to]);
	if (low[x]==dfn[x]){
		++co;
		int y=19260817+1;
		for (;y!=x;){
			y=stk[(*stk)--];
			vis[y]=0;
			be[y]=co;
		}
	}
}
void work1(){
	if ((*q)!=2) return;
	add(q[1]*2-1,q[2]*2);
	add(q[2]*2-1,q[1]*2);
	add(q[1]*2,q[2]*2-1);
	add(q[2]*2,q[1]*2-1);
}
//-1:
//0:
void work2(){
	int p=0;
	For(i,1,*q){
		add(q[i]*2-1,p);
		add(++nd,p);
		add(nd,q[i]*2);
		p=nd;
	}
	p=0;
	Rep(i,*q,1){
		add(q[i]*2-1,p);
		add(++nd,p);
		add(nd,q[i]*2);
		p=nd;
	}
	//For(i,1,*q) For(j,1,*q)
	//	if (i!=j) add(q[i]*2-1,q[j]*2);
}
bool check(int v){
	memset(head,0,sizeof(head));
	memset(dfn,0,sizeof(dfn));
	nd=2*m; tot=0;
	For(i,1,m)
		if (E[i].v>v)
			add(i*2-1,i*2);
	For(i,1,n){
		if (!vec[i].size()) continue;
		q[0]=1; q[1]=vec[i][0];
		int cnt=0;
		For(j,1,vec[i].size()-1){
			if (E[vec[i][j]].c!=E[q[*q]].c)
				cnt+=(*q)-1,work1(),*q=0;
			q[++*q]=vec[i][j];
		}
		cnt+=(*q)-1,work1(),*q=0;
		if (cnt>1) return 0;
		For(j,0,vec[i].size()-1)
			q[++*q]=vec[i][j];
		work2();
	}
	For(i,1,m*2)
		if (!dfn[i])
			tarjan(i);
	//For(i,1,m*2)
	//	printf("%d ",be[i]);
	//puts("");
	For(i,1,m)
		if (be[i*2-1]==be[i*2])
			return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	int l=0,r=0,ans=-1;
	For(i,1,m){
		scanf("%d%d",&E[i].x,&E[i].y);
		scanf("%d%d",&E[i].c,&E[i].v);
		r=max(r,E[i].v+1);
		vec[E[i].x].PB(i);
		vec[E[i].y].PB(i);
	}
	For(i,1,n)
		sort(vec[i].begin(),vec[i].end(),cmp);
	//puts(check(8)?"Y":"N");
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	if (ans==-1)
		return puts("No"),0;
	check(ans);
	For(i,1,m)
		if (be[i*2-1]<be[i*2])
			q[++top]=i;
	printf("Yes\n%d %d\n",ans,top);
	For(i,1,top) printf("%d ",q[i]);
}