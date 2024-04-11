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
#define mod 998244353
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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 1000005
#define lim 1000001
struct SMT
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	struct Node
	{
		int val,tag,sum;
	};
	Node t[N*4];
	void pushup(int u)
	{
		t[u].val=min(t[ls].val,t[rs].val);
		// t[u].val=min(t[ls].val==0?inf:t[ls].val,t[rs].val==0?inf:t[rs].val);
		t[u].sum=0;
		if(t[u].val==t[ls].val) t[u].sum+=t[ls].sum;
		if(t[u].val==t[rs].val) t[u].sum+=t[rs].sum;
	}
	void doit(int u,int v)
	{
		t[u].val+=v,t[u].tag+=v;
	}
	void pushdown(int u)
	{
		doit(ls,t[u].tag),doit(rs,t[u].tag);
		t[u].tag=0;
	}
	void update(int u,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{
			// printf("%d %d %d + %d\n",u,l,r,v);
			doit(u,v);
			// printf("%d %d %d * %d %d\n",u,l,r,t[u].val,t[u].sum);
			return ;
		}
		pushdown(u);
		if(mid>=L) update(ls,l,mid,L,R,v);
		if(mid<R) update(rs,mid+1,r,L,R,v);
		if(!t[u].sum) t[u].val=0;
		pushup(u);
	}
	void update(int u,int l,int r,int pl,int v)
	{
		if(l==r)
		{
			t[u].sum+=v;
			return ;
		}
		pushdown(u);
		if(pl<=mid) update(ls,l,mid,pl,v);
		else update(rs,mid+1,r,pl,v);
		if(!t[u].sum) t[u].val=0;
		pushup(u);
	}
	int query(int u,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)
		{
			// printf("%d %d %d - %d %d\n",u,l,r,t[u].val,t[u].sum);
			return t[u].val==1?t[u].sum:0;
		}
		pushdown(u);
		int ans=0;
		if(mid>=L) ans+=query(ls,l,mid,L,R);
		if(mid<R) ans+=query(rs,mid+1,r,L,R);
		return ans;
	}
}smt;
void upd1(int u,int v)
{
	smt.update(1,0,lim,u,v);
}
void upd2(int x,int y,int v)
{
	if(x>y) swap(x,y);
	// printf("%d %d\n",x,y-1);
	smt.update(1,0,lim,x,y-1,v);
}
int query(){return smt.query(1,0,lim,1,lim-1);}
int a[N],n,Q;
signed main()
{
	cin>>n>>Q;
	for(int i=1;i<=n;i++) a[i]=read(),upd1(a[i],1);
	a[0]=lim,upd1(a[0],1); a[n+1]=0,upd1(a[n+1],1);
	// printf("%d\n",query());
	for(int i=0;i<=n;i++) upd2(a[i],a[i+1],1);
	// printf("%d\n",query());
	while(Q--)
	{
		int pos=read(),val=read();
		upd1(a[pos],-1),upd2(a[pos-1],a[pos],-1),upd2(a[pos],a[pos+1],-1);
		a[pos]=val;
		upd1(a[pos],1),upd2(a[pos-1],a[pos],1),upd2(a[pos],a[pos+1],1);
		printf("%d\n",query());
	}
	return 0;
}