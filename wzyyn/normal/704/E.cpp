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
const int N=100005;
const double eps=1e-9;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n,Q;
int sz[N],fa[N],dep[N];
int top[N],dfn[N],len[N];
struct line{
	double S,T;
	int l,r;
	double v;
	double F(double x){
		return l+v*(x-S);
	}
}q[N];
vector<line> vec[N];
double T,ans;
struct CMPER{
	bool operator ()(const int &x,const int &y){
		return q[x].F(T)<q[y].F(T);
	}
};
set<int,CMPER> S;
struct query{
	double t;
	int id;
	bool operator <(const query &a)const{
		if (fabs(t-a.t)<eps)
			return id>a.id;
		return t<a.t;
	}
}que[N*2];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs1(int x){
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			fa[e[i].to]=x;
			dep[e[i].to]=dep[x]+1;
			dfs1(e[i].to);
			sz[x]+=sz[e[i].to];
		}
}
void dfs2(int x,int tp){
	top[x]=tp;
	dfn[x]=++*dfn;
	int k=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&sz[e[i].to]>sz[k])
			k=e[i].to;
	if (k) dfs2(k,tp);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=k)
			dfs2(e[i].to,e[i].to);
}
int LCA(int x,int y){
	for (;top[x]!=top[y];x=fa[top[x]])
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
	return dep[x]<dep[y]?x:y;
}
int dis(int x,int y){
	return dep[x]+dep[y]-2*dep[LCA(x,y)];
}
void insert(int x,int y,double S,double T,int v){
	//printf("%.10lf %.10lf\n",S,T);
	int L=LCA(x,y);
	for (;top[x]!=top[L];x=fa[top[x]]){
		int len=dfn[x]-dfn[top[x]]+1;
		vec[top[x]].PB((line){S,S+1.0*len/v,len,0,-v});
		S+=1.0*len/v;
	}
	for (;top[y]!=top[L];y=fa[top[y]]){
		int len=dfn[y]-dfn[top[y]]+1;
		vec[top[y]].PB((line){T-1.0*len/v,T,0,len,v});
		T-=1.0*len/v;
	}
	int px=dfn[x]-dfn[top[x]]+1;
	int py=dfn[y]-dfn[top[y]]+1;
	if (dfn[x]>dfn[y])
		vec[top[x]].PB((line){S,T,px,py,-v});
	else vec[top[x]].PB((line){S,T,px,py,v});
}
void update(int idx,int idy){
	//printf("UPDATE %d %d\n",idx,idy);
	if (q[idx].S>q[idy].S) swap(idx,idy);
	if (q[idx].T+eps<q[idy].S) return;
	double posi=q[idx].F(q[idy].S);
	if (fabs(q[idx].v-q[idy].v)<=eps){
		if (fabs(posi-q[idy].l)<=eps)
			ans=min(ans,q[idy].S);
		return;
	}
	double T=(q[idy].l-posi)/(q[idx].v-q[idy].v);
	if (T<-eps||q[idy].S+T>min(q[idy].T,q[idx].T)+eps) return;
	ans=min(ans,q[idy].S+T);
}
void erase(int id){
	S.erase(id);
	set<int,CMPER>::iterator pre,nxt;
	pre=nxt=S.lower_bound(id);
	if (pre!=S.begin()&&nxt!=S.end())
		update(*(--pre),*nxt);
}
void insert(int id){
	set<int,CMPER>::iterator pre,nxt;
	pre=nxt=S.lower_bound(id);
	if (pre!=S.begin())
		update(*(--pre),id);
	if (nxt!=S.end())
		update(*(nxt),id);
	S.insert(id);
}
void solve(int x){
	int m=vec[x].size();
	int top=0;
	For(i,0,m-1){
		q[i+1]=vec[x][i];
		//printf("%.10lf %.10lf %d %d %.10lf\n",q[i+1].S,q[i+1].T,q[i+1].l,q[i+1].r,q[i+1].v);
		que[++top]=(query){q[i+1].S,i+1};
		que[++top]=(query){q[i+1].T,-i-1};
	}
	S.clear();
	sort(que+1,que+top+1);
	For(i,1,top){
		T=que[i].t;
		if (que[i].t+eps>=ans) break;
		if (que[i].id<0) erase(-que[i].id);
		else insert(que[i].id);
	}
	//printf("%d %.10lf\n",x,ans);
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&Q);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs1(1);
	dfs2(1,1);
	For(i,1,Q){
		int x,y,v,T;
		scanf("%d%d%d%d",&T,&v,&x,&y);
		insert(x,y,T,T+1.0*dis(x,y)/v,v);
	}
	ans=1e6;
	For(i,1,n)
		len[top[i]]=max(len[top[i]],dep[i]-dep[top[i]]+1);
	For(i,1,n)
		if (top[i]==i)
			solve(i);
	if (ans>5e5) puts("-1");
	else printf("%.10lf\n",ans);
}
/*
5 2
1 2
2 3
3 4
2 5
1 1 1 4
1 1 3 2
*/