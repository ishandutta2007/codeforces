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
inline char rdchar()
{
	char ch=getchar();
	while(!(ch>='a'&&ch<='z')&&!(ch>='A'&&ch<='Z')&&!(ch>='0'&&ch<='9')) ch=getchar();
	return ch;
}
typedef pair<int,int> pii;
#define N 200005
char s[N];
int n,Q,k;
int getv(char x,char y){return (x-'a')*k+(y-'a')+1;}
struct SMT2
{
	int t[N*4],tag[N*4];
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	void build(int u,int l,int r)
	{
		tag[u]=-1;
		if(l==r)
		{
			t[u]=s[l];
			return ;
		}
		build(ls,l,mid),build(rs,mid+1,r);
	}
	void pushdown(int u)
	{
		if(tag[u]==-1) return ;
		tag[ls]=tag[rs]=tag[u];
		t[ls]=t[rs]=tag[u];
		tag[u]=-1;
	}
	void update(int u,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{
			t[u]=tag[u]=v;
			return ;
		}
		pushdown(u);
		if(mid>=L) update(ls,l,mid,L,R,v);
		if(mid<R) update(rs,mid+1,r,L,R,v);
	}
	int query(int u,int l,int r,int pl)
	{
		if(l==r) return t[u];
		pushdown(u);
		if(pl<=mid) return query(ls,l,mid,pl);
		else return query(rs,mid+1,r,pl);
	}
}smt2;
struct SMT
{
	int t[N*4][105],tag[N*4],le[N*4],ri[N*4];
	void build(int u,int l,int r)
	{
		le[u]=l,ri[u]=r;
		if(l==r)
		{
			int v=getv(s[l],s[l+1]);
			t[u][v]=1;
			return ;
		}
		build(ls,l,mid),build(rs,mid+1,r);
		for(int i=1;i<=k*k;i++) t[u][i]=t[ls][i]+t[rs][i];
	}
	void doit(int u,int v)
	{
		tag[u]=v;
		memset(t[u],0,sizeof(t[u])); t[u][v]=ri[u]-le[u]+1;
	}
	void pushdown(int u)
	{
		if(!tag[u]) return ;
		doit(ls,tag[u]),doit(rs,tag[u]);
		tag[u]=0;
	}
	void update(int u,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{
			doit(u,v);
			return ;
		}
		pushdown(u);
		if(mid>=L) update(ls,l,mid,L,R,v);
		if(mid<R) update(rs,mid+1,r,L,R,v);
		for(int i=1;i<=k*k;i++) t[u][i]=t[ls][i]+t[rs][i];
	}
	int query(int v){return t[1][v];}
}smt;
char t[N];
signed main()
{
	cin>>n>>Q>>k;
	if(n==1)
	{
		while(Q--)
		{
			int opt=read();
			if(opt==1)
			{
				int l=read(),r=read(); char x=rdchar();
			}
			else printf("%d\n",1);
		}
		return 0;
	}
	scanf("%s",s+1);
	smt2.build(1,1,n);
	smt.build(1,1,n-1);
	while(Q--)
	{
		int opt=read();
		if(opt==1)
		{
			int l=read(),r=read(); char x=rdchar();
			smt2.update(1,1,n,l,r,x);
			if(l!=1)
			{
				int L=smt2.query(1,1,n,l-1);
				smt.update(1,1,n-1,l-1,l-1,getv(L,x));
			}
			if(l!=r) smt.update(1,1,n-1,l,r-1,getv(x,x));
			if(r!=n)
			{
				int R=smt2.query(1,1,n,r+1);
				smt.update(1,1,n-1,r,r,getv(x,R));
			}
		}
		else
		{
			int ans=0;
			scanf("%s",t+1);
			for(int i=1;i<=k;i++)
			{
				for(int j=1;j<=i;j++) ans+=smt.query(getv(t[i],t[j]));
			}
			printf("%d\n",ans+1);
		}
	}
	return 0;
}