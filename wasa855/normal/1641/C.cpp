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
#define N 200055
int n,Q;
struct SMT
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	int t[N*4];
	void pushdown(int u) {t[ls]|=t[u],t[rs]|=t[u];}
	void update(int u,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) {t[u]=1; return ;}
		pushdown(u);
		if(mid>=L) update(ls,l,mid,L,R);
		if(mid<R) update(rs,mid+1,r,L,R);
		t[u]=t[ls]&t[rs];
	}
	int qryl(int u,int l,int r,int pos)
	{
		if(l==r) return t[u]?-1:l;
		pushdown(u);
		if(l<=pos&&pos<=r)
		{
			if(pos<=mid) return qryl(ls,l,mid,pos);
			else
			{
				int t=qryl(rs,mid+1,r,pos);
				if(t==-1) return qryl(ls,l,mid,pos);
				else return t;
			}
		}
		if(t[rs]) return qryl(ls,l,mid,pos);
		else return qryl(rs,mid+1,r,pos);
	}
	int qryr(int u,int l,int r,int pos)
	{
		if(l==r) return t[u]?-1:l;
		pushdown(u);
		if(l<=pos&&pos<=r)
		{
			if(pos>mid) return qryr(rs,mid+1,r,pos);
			else
			{
				int t=qryr(ls,l,mid,pos);
				if(t==-1) return qryr(rs,mid+1,r,pos);
				else return t;
			}
		}
		if(t[ls]) return qryr(rs,mid+1,r,pos);
		else return qryr(ls,l,mid,pos);
	}
}smt;
// set<int> s[N];
// int Min(int x,int y) {return *s[x].begin()<*s[y].begin()?x:y;}
/*
struct SMT2
{
	int t[N*4];
	void pushup(int u) {t[u]=Min(t[ls],t[rs]);}
	void build(int u,int l,int r)
	{
		if(l==r) {t[u]=l; return ;}
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(u);
	}
	void update(int u,int l,int r,int pos)
	{
		if(l==r) return ;
		if(pos<=mid) update(ls,l,mid,pos);
		else update(rs,mid+1,r,pos);
		pushup(u);
	}
	int query(int u,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return t[u];
		if(mid>=L&&mid<R) return Min(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
		if(mid>=L) return query(ls,l,mid,L,R);
		else return query(rs,mid+1,r,L,R);
	}
}smt2;
*/
struct SMT2
{
	set<int> s[N*4];
	// void build(int u,int l,int r)
	// {
		// s[u].insert(0);
		// if(l==r) return ;
		// build(ls,l,mid),build(rs,mid+1,r);
		// pushup(u);
	// }
	void update(int u,int l,int r,int pos,int v)
	{
		s[u].insert(v);
		if(l==r) return ;
		if(pos<=mid) update(ls,l,mid,pos,v);
		else update(rs,mid+1,r,pos,v);
	}
	int query(int u,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R)
		{
			auto it=s[u].lower_bound(v);
			if(it==s[u].end()) return inf;
			else return *it;
		}
		int ans=inf;
		if(mid>=L) ans=min(ans,query(ls,l,mid,L,R,v));
		if(mid<R) ans=min(ans,query(rs,mid+1,r,L,R,v));
		return ans;
	}
}smt2;
int bad[N];
signed main()
{
	cin>>n>>Q;
	n+=8;
	while(Q--)
	{
		int op=read();
		if(op==0)
		{
			int l=read()+4,r=read()+4,v=read();
			int pos=0;
			if(v==0)
			{
				smt.update(1,1,n,l,r);
				pos=smt.qryl(1,1,n,l)+1;
			}
			else
			{
				smt2.update(1,1,n,l,r);
				if(smt.qryr(1,1,n,l+1)>r||l==r) bad[l]=1;
				pos=smt.qryl(1,1,n,l)+1;
			}
			int L=pos,R=smt.qryr(1,1,n,L)-1;
			if(smt.qryl(1,1,n,L)==L) continue;
			{
				int ql=smt.qryl(1,1,n,L-2)+1;
				int res=smt2.query(1,1,n,ql,L-1,L-1);
				if(res<=R) bad[L-1]=1;
			}
			int res=smt2.query(1,1,n,L,R+1,R+1);
			int ned=smt.qryr(1,1,n,R+2);
			// if(ned==R+2)
			// printf("%d %d ^ %d %d\n",L,R,res,ned);
			if(res<ned) bad[R+1]=1;
		}
		else
		{
			int p=read()+4;
			if(bad[p]) printf("YES\n");
			else if(smt.qryl(1,1,n,p)==p) printf("N/A\n");
			else printf("NO\n");
		}
	}
	return 0;
}