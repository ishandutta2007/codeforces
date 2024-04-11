#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 1000000007
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 2005
int x[N],y[N],col[N];
struct NODE
{
	int x,y,id,col;
	NODE(int a=0,int b=0,int c=0,int d=0){x=a,y=b,id=c,col=d;}
};
vector<NODE> vx[N];
int _x[N],_y[N],cx,cy;
int n,k,l;
struct Node
{
	int id,y,col;
	Node(int A=0,int B=0,int C=0){id=A,y=B,col=C;}
	bool operator < (const Node &x) const
	{
		if(y!=x.y) return y<x.y;
		return id<x.id;
	}
};
multiset<Node> vy[N];
set<Node> s;
Node a[N];
int siz,las[N],rid[N];
int nxt[N],dx[N];
struct SMT
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	struct Node
	{
		int sum,mx,se,val,tag;
	};
	Node t[N*4];
	void pushup(int u)
	{
		t[u].sum=add(t[ls].sum,t[rs].sum);
		if(t[ls].mx>t[rs].mx)
		{
			t[u].mx=t[ls].mx,t[u].se=max(t[ls].se,t[rs].mx);
			t[u].val=t[ls].val;
		}
		else if(t[ls].mx<t[rs].mx)
		{
			t[u].mx=t[rs].mx,t[u].se=max(t[ls].mx,t[rs].se);
			t[u].val=t[rs].val;
		}
		else
		{
			t[u].mx=t[ls].mx,t[u].se=max(t[ls].se,t[rs].se);
			t[u].val=add(t[ls].val,t[rs].val);
		}
	}
	void build(int u,int l,int r)
	{
		t[u].tag=inf;
		if(l==r)
		{
			t[u].sum=mul(_y[nxt[l]],dx[l]);
			t[u].mx=_y[nxt[l]],t[u].val=dx[l];
			return ;
		}
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(u);
	}
	void update(int u,int l,int r,int L,int R,int v);
	void doit(int u,int l,int r,int L,int R,int v)
	{
		if(l==r)
		{
			t[u].mx=min(t[u].mx,v);
			t[u].sum=mul(t[u].mx,t[u].val);
//			printf("%d %d %d %d %d %d : %d\n",u,l,r,L,R,v,t[u].sum);
			return ;
		}
		if(v>=t[u].mx) return ;
		else if(v>t[u].se)
		{
			t[u].sum=sub(t[u].sum,mul(t[u].mx-v,t[u].val));
			t[u].tag=t[u].mx=v;
		}
		else
		{
			pushdown(u,l,r);
			update(ls,l,mid,L,R,v),update(rs,mid+1,r,L,R,v);
			pushup(u);
		}
	}
	void pushdown(int u,int l,int r)
	{
		if(t[u].tag!=inf)
		{
			doit(ls,l,mid,l,mid,t[u].tag);
			doit(rs,mid+1,r,mid+1,r,t[u].tag);
			t[u].tag=inf;
		}
	}
	int query(){return t[1].sum;}
}smt;
void SMT::update(int u,int l,int r,int L,int R,int v)
{
//	printf("%d %d %d %d %d %d\n",u,l,r,L,R,v);
	if(L<=l&&r<=R)
	{
		SMT::doit(u,l,r,L,R,v);
		return ;
	}
	pushdown(u,l,r);
	if(mid>=L) SMT::update(ls,l,mid,L,R,v);
	if(mid<R) SMT::update(rs,mid+1,r,L,R,v);
	SMT::pushup(u);
//	printf("%d %d %d %d %d %d -- %d\n",u,l,r,L,R,v,t[u].sum);
}
int solve(int l)
{
	int r=cx-1;
//	printf("++ %d %d\n",l,r);
	siz=0;
	for(int i=l;i<=r;i++)
	{
//		cout<<i<<" :\n";
		for(auto [x,y,id,col]:vx[i])
		{
			a[++siz]=Node(id,y,col);
//			printf("%d %d %d %d\n",x,y,id,col);
		}
	}
	a[siz+1]=Node(0,cy);
	sort(a+1,a+siz+1);
	for(int i=1;i<=siz;i++)
	{
		s.insert(Node(i,a[i].y,a[i].col));
		vy[a[i].col].insert(Node(i,a[i].y,a[i].col));
	}
	for(int i=1;i<=siz;i++) dx[i]=_y[a[i+1].y]-_y[a[i].y];
	memset(las,0,sizeof(las));
	for(int i=1;i<=siz;i++)
	{
		las[a[i].col]=a[i].y;
		nxt[i]=inf;
		for(int j=1;j<=k;j++) nxt[i]=min(nxt[i],las[j]);
	}
	for(int i=1;i<=siz;i++) rid[a[i].id]=i;
//	for(int i=1;i<=siz;i++)
//	{
//		printf("%d %d %d : %d %d\n",a[i].id,a[i].y,a[i].col,dx[i],_y[nxt[i]]);
//	}
//	printf("** %d\n",siz);
	smt.build(1,1,siz);
	int ans=mul(smt.query(),_x[r+1]-_x[r]);
//	cout<<ans<<endl;
	for(int i=r;i>=l;i--)
	{
		for(auto [x,y,id,col]:vx[i])
		{
			id=rid[id];
			Node cur(id,y,col);
			int v; auto tmp=vy[col].find(cur);
//			printf("\/\/ %d %d %d\n",(*tmp).id,(*tmp).y,(*tmp).col);
			if(tmp==vy[col].begin()) v=0;
			else
			{
				--tmp; v=_y[(*tmp).y]; ++tmp;
			}
			int R;
			if(tmp==--vy[col].end()) R=siz+1;
			else
			{
				++tmp; R=(*tmp).id; --tmp;
			}
			vy[col].erase(tmp);
//			printf("%d %d %d\n",id,R-1,v);
			smt.update(1,1,siz,id,R-1,v);
		}
		ans=add(ans,mul(smt.query(),_x[i]-_x[i-1]));
//		cout<<ans<<endl;
	}
	for(int i=l;i<=r;i++) vy[i].clear();
	s.clear();
//	printf("--- %d\n",ans);
	return ans;
}
signed main()
{
	cin>>n>>k>>l;
	for(int i=1;i<=n;i++)
	{
		_x[i]=x[i]=read()+1,_y[i]=y[i]=read()+1,col[i]=read();
	}
	_x[n+1]=l+1,_y[n+1]=l+1;_x[n+2]=0,_y[n+2]=0;
	sort(_x+1,_x+n+3),sort(_y+1,_y+n+3);
	cx=unique(_x+1,_x+n+3)-_x-1,cy=unique(_y+1,_y+n+3)-_y-1;
	for(int i=1;i<=n;i++) x[i]=lower_bound(_x+1,_x+cx+1,x[i])-_x,y[i]=lower_bound(_y+1,_y+cy+1,y[i])-_y;
	for(int i=1;i<=n;i++) vx[x[i]].eb(x[i],y[i],i,col[i]);
	int las=0,ans=0;
	for(int i=2;i<cx;i++)
	{
		ans=add(ans,mul(solve(i),_x[i]-las));
		las=_x[i];
	}
	cout<<ans<<endl;
	return 0;
}