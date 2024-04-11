#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
using namespace std;
const int N=100005;
struct Num
{
	ll x,y;
	inline Num(ll xx=0,ll yy=1){x=xx,y=yy;}
	inline Num operator=(Num a){x=a.x,y=a.y;return *this;}
};
inline Num normal(Num a)
{
	ll d=__gcd(a.x,a.y);
	a.x/=d,a.y/=d;
	if(a.y<0)a.y=-a.y,a.x=-a.x;
	return a;
}
inline Num operator-(Num a){return Num(-a.x,a.y);}
inline Num operator*(Num a,Num b){return Num(a.x*b.x,a.y*b.y);}
inline Num operator/(Num a,Num b){return normal(Num(a.x*b.y,a.y*b.x));}
inline Num operator+(Num a,Num b){return Num(a.x*b.y+a.y*b.x,a.y*b.y);}
inline Num operator-(Num a,Num b){return Num(a.x*b.y-a.y*b.x,a.y*b.y);}
inline Num operator+=(Num&a,Num b){return a=a+b;}
inline Num operator-=(Num&a,Num b){return a=a-b;}
inline Num operator*=(Num&a,Num b){return a=a*b;}
inline Num operator/=(Num&a,Num b){return a=a/b;}
inline bool operator==(Num a,Num b){return a.x*b.y==a.y*b.x;}
inline bool operator<(Num a,Num b){return a.x*b.y<b.x*a.y;}
inline bool operator>(Num a,Num b){return b<a;}
inline bool operator<=(Num a,Num b){return !(a>b);}
inline bool operator>=(Num a,Num b){return !(a<b);}
inline bool operator!=(Num a,Num b){return !(a==b);}
struct Treap
{
	#define lc tree[x].child[0]
	#define rc tree[x].child[1]
	struct Node
	{
		int child[2];
		int key;
		int st;
		Num ti,vi;
	}tree[N];
	int tot;
	void rotate(int&x,int d)
	{
		int y=tree[x].child[d];
		tree[x].child[d]=tree[y].child[d^1];
		tree[y].child[d^1]=x;
		x=y;
	}
	void ins(int&x,int p,Num t,Num v)
	{
		if(!x)
		{
			t=normal(t),v=normal(v);
			x=++tot;
			tree[tot].st=p;
			tree[tot].ti=t;
			tree[tot].vi=v;
			tree[tot].key=rand();
			tree[tot].child[0]=tree[tot].child[1]=0;
			return;
		}
		int d;
		if(t>tree[x].ti)d=(t-tree[x].ti)*tree[x].vi+tree[x].st<=p;
		else d=(tree[x].ti-t)*v+p>=tree[x].st;
		ins(tree[x].child[d],p,t,v);
		if(tree[tree[x].child[d]].key>tree[x].key)rotate(x,d);
		return;
	}
	void del(int&x,int p,Num t,Num v)
	{
		if(tree[x].st==p&&tree[x].ti==t&&tree[x].vi==v)
		{
			if(!lc||!rc)
			{
				x=lc+rc;
				return;
			}
			int d=tree[rc].key<tree[lc].key;
			rotate(x,d);
			del(tree[x].child[!d],p,t,v);
			return;
		}
		int d;
		if(t>tree[x].ti)d=(t-tree[x].ti)*tree[x].vi+tree[x].st<=p;
		else d=(tree[x].ti-t)*v+p>=tree[x].st;
		del(tree[x].child[d],p,t,v);
	}
	int upper(int&x,int p,Num t,Num v)
	{
		if(!x)return 0;
		int ans=0;
		int d;
		if(t>tree[x].ti)d=(t-tree[x].ti)*tree[x].vi+tree[x].st<=p;
		else d=(tree[x].ti-t)*v+p>=tree[x].st;
//		printf("x=%d,d=%d\n",x,d);
		if(!d)ans=x;
		int res=upper(tree[x].child[d],p,t,v);
		if(tree[ans].ti>tree[res].ti)d=(tree[ans].ti-tree[res].ti)*tree[res].vi+tree[res].st<tree[ans].st;
		else d=(tree[res].ti-tree[ans].ti)*tree[ans].vi+tree[ans].st>tree[res].st;
//		printf("ans=%d,res=%d\n",ans,res);
//		Num p1=(tree[ans].ti-tree[res].ti)*tree[res].vi+tree[res].st,p2=tree[ans].st;
//		printf("%lld/%lld,%lld/%lld d=%d\n",p1.x,p1.y,p2.x,p2.y,d);
		if(!ans||(res&&d))ans=res;
//		printf("ans=%d\n",ans);
		return ans;
	}
	int lower(int&x,int p,Num t,Num v)
	{
		if(!x)return 0;
		int ans=0;
		int d;
		if(t>tree[x].ti)d=(t-tree[x].ti)*tree[x].vi+tree[x].st<=p;
		else d=(tree[x].ti-t)*v+p>=tree[x].st;
//		printf("%d %d\n",x,d);
		if(d)ans=x;
		int res=lower(tree[x].child[d],p,t,v);
//		printf("ans=%d,res=%d\n",ans,res);
		if(tree[ans].ti>tree[res].ti)d=(tree[ans].ti-tree[res].ti)*tree[res].vi+tree[res].st<=tree[ans].st;
		else d=(tree[res].ti-tree[ans].ti)*tree[ans].vi+tree[ans].st>=tree[res].st;
		if(!ans||(res&&!d))ans=res;
//		printf("ans=%d\n",ans);
		return ans;
	}
	#undef lc
	#undef rc
}T;
priority_queue<Num,vector<Num>,greater<Num> >q,del;
struct Edge
{
	int to;
	int nxt;
}e[2*N];
struct Path
{
	int u,v;
	Num st,vi;
	Path(int uu=0,int vv=0,Num stt=0,Num vii=0){u=uu,v=vv,st=stt,vi=vii;}
};
struct Query
{
	int type;
	Num t;
	Path x;
	Query(int ti=0,Num tt=0,Path xx=0){type=ti,t=tt,x=xx;}
};
int n,m,tot,edgenum,head[N],pa[N],dep[N],size[N],dfn[N],son[N],top[N],in[N];
vector<Path>p[N];
vector<Query>a[N];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs1(int node)
{
	size[node]=1;
	dep[node]=dep[pa[node]]+1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs1(to);
		size[node]+=size[to];
		if(size[to]>size[son[node]])son[node]=to;
	}
}
int ind=0;
void dfs2(int node,int t)
{
	dfn[node]=++ind;
	top[node]=t;
	if(node==t)
	{
//		printf("%d start at %d\n",tot+1,node);
		in[node]=++tot;
	}
	else in[node]=in[t];
	if(son[node])dfs2(son[node],t);
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node]||to==son[node])continue;
		dfs2(to,to);
	}
}
int _au[N],_bu[N],_av[N],_bv[N];
void split(int u,int v,Num st,Num val)
{
	int ori=u;
//	printf("split(%d,%d,%lld/%lld,%lld/%lld)\n",u,v,st.x,st.y,val.x,val.y);
	int*au=_au,*bu=_bu,*av=_av,*bv=_bv;
	int num1=0,num2=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]])
		{
			swap(u,v);
			swap(au,av);
			swap(bu,bv);
			swap(num1,num2);
		}
		au[++num1]=u;
		bu[num1]=pa[top[u]];
		u=pa[top[u]];
	}
	if(dep[u]<dep[v])
	{
		swap(u,v);
		swap(au,av);
		swap(bu,bv);
		swap(num1,num2);
	}
	au[++num1]=u;
	bu[num1]=v;
	if(au[1]!=ori||!num1)
	{
		swap(u,v);
		swap(au,av);
		swap(bu,bv);
		swap(num1,num2);
	}
	for(int i=1;i<=num1;i++)
	{
		int x=top[au[i]];
		st=normal(st);
		Num en=st+(dep[au[i]]-dep[bu[i]])/val;
//		printf("1 from %d to %d,from %lld/%lld to %lld/%lld,push %d\n",au[i],bu[i],st.x,st.y,en.x,en.y,in[x]);
		p[in[x]].push_back(Path(dep[au[i]]-dep[x]+2,dep[bu[i]]-dep[x]+2,st,-val));
		st=en;
	}
	for(int i=num2;i>=1;i--)
	{
		int x=top[av[i]];
		st=normal(st);
		Num en=st+(dep[av[i]]-dep[bv[i]])/val;
//		printf("2 from %d to %d,from %lld/%lld to %lld/%lld,push %d\n",bv[i],av[i],st.x,st.y,en.x,en.y,in[x]);
		p[in[x]].push_back(Path(dep[bv[i]]-dep[x]+2,dep[av[i]]-dep[x]+2,st,val));
		st=en;
	}
}
bool cmp(Query x,Query y)
{
	return x.t<y.t||(x.t==y.t&&x.type>y.type);
}
Num calc(Num p1,Num t1,Num v1,Num p2,Num t2,Num v2)
{
	if(t1>t2)swap(t1,t2),swap(p1,p2),swap(v1,v2);
	p1+=(t2-t1)*v1,t1=t2;
	if(p1>p2)swap(p1,p2),swap(t1,t2),swap(v1,v2);
	if(p1==p2)return t1;
//	printf("%lld/%lld time=%lld/%lld,speed=%lld/%lld\n",p1.x,p1.y,t1.x,t1.y,v1.x,v1.y);
//	printf("%lld/%lld time=%lld/%lld,speed=%lld/%lld\n",p2.x,p2.y,t2.x,t2.y,v2.x,v2.y);
	if(v1<=v2)return 2147483647;
	Num ans=(p2-p1)/(v1-v2)+t1;
	ans=normal(ans);
//	printf("%lld/%lld\n",ans.x,ans.y);
	return ans;
}
bool cmp_tmp(Path a,Path b)
{
	return a.st<b.st;
}
Num solve(int x)
{
//	printf("solve(%d):\n",x);
	q.push(2147483647);
	sort(p[x].begin(),p[x].end(),cmp_tmp);
	for(auto pa:p[x])
	{
		pa.st=normal(pa.st);
		pa.vi=normal(pa.vi);
//		printf("path:from %d to %d, t=%.12lf, v=%lld/%lld\n",pa.u,pa.v,(double)pa.st.x/(double)pa.st.y,pa.vi.x,pa.vi.y);
		a[x].push_back(Query(1,pa.st,pa));
		a[x].push_back(Query(-1,normal(pa.st+(pa.v-pa.u)/pa.vi),pa));
	}
	sort(a[x].begin(),a[x].end(),cmp);
	T.tot=0;
	int root=0;
	Num ans=2147483647;
	while(!q.empty())q.pop();
	while(!del.empty())del.pop();
	for(auto b:a[x])
	{
		if(!q.empty()&&q.top()<=b.t)ans=min(ans,q.top());
		if(ans<=b.t)break;
//		if(b.type==1)printf("ins ");
//		else printf("del ");
//		printf("time=%.12lf,pos=%d,st=%.12lf,v=%.12lf\n",(double)b.t.x/(double)b.t.y,b.x.u,(double)b.x.st.x/(double)b.x.st.y,(double)b.x.vi.x/(double)b.x.vi.y);
		if(b.type==1)
		{
			int aa=T.lower(root,b.x.u,b.x.st,b.x.vi);
			int bb=T.upper(root,b.x.u,b.x.st,b.x.vi);
			auto x=T.tree[aa];
			auto y=T.tree[bb];
			T.ins(root,b.x.u,b.x.st,b.x.vi);
//			printf("l=%d,r=%d\n",aa,bb);
			if(aa&&bb)del.push(calc(x.st,x.ti,x.vi,y.st,y.ti,y.vi));
			if(aa)q.push(calc(x.st,x.ti,x.vi,b.x.u,b.x.st,b.x.vi));
			if(bb)q.push(calc(b.x.u,b.x.st,b.x.vi,y.st,y.ti,y.vi));
		}
		else
		{
			T.del(root,b.x.u,b.x.st,b.x.vi);
			int aa=T.lower(root,b.x.u,b.x.st,b.x.vi);
			int bb=T.upper(root,b.x.u,b.x.st,b.x.vi);
			auto x=T.tree[aa];
			auto y=T.tree[bb];
//			printf("l=%d,r=%d\n",aa,bb);
			if(aa&&bb)q.push(calc(x.st,x.ti,x.vi,y.st,y.ti,y.vi));
			if(aa)del.push(calc(x.st,x.ti,x.vi,b.x.u,b.x.st,b.x.vi));
			if(bb)del.push(calc(b.x.u,b.x.st,b.x.vi,y.st,y.ti,y.vi));
		}
		while(!q.empty()&&!del.empty()&&q.top()==del.top())
		{
			q.pop();
			del.pop();
		}
//		if(!q.empty())printf("q %lld/%lld\n",q.top().x,q.top().y);
//		if(!del.empty())printf("d %lld/%lld\n",del.top().x,del.top().y);
	}
	ans=normal(ans);
//	exit(0);
//	printf("%lld/%lld,%.12lf\n",ans.x,ans.y,(double)ans.x/(double)ans.y);
	return ans;
}
int main()
{
//	srand(100);
//	n=m=100000;
//	printf("%d %d\n",n,m);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v;
//		u=i+1,v=rand()%i+1;
//		printf("%d %d\n",u,v);
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	dfs1(1);
	dfs2(1,1);
	while(m--)
	{
		int t,c,v,u;
//		t=rand()%10000+1,c=rand()%10000+1,v=rand()%n+1,u=rand()%n+1;
//		printf("%d %d %d %d\n",t,c,v,u);
		scanf("%d%d%d%d",&t,&c,&v,&u);
		split(v,u,t,c);
	}
	Num ans=2147483647;
	for(int i=1;i<=tot;i++)ans=min(ans,solve(i));
	ans=normal(ans);
	if(ans==2147483647)printf("-1\n");
	else printf("%.12lf\n",(double)ans.x/(double)ans.y);
	return 0;
}