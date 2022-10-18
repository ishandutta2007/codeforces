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
#define N 500005
int a[N],b[N],l[N],r[N],op[N],sum[N],n,lim,cnt;
struct SMT
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	int t[N*4],tag[N*4];
	void build(int u,int l,int r)
	{
		tag[u]=0;
		if(l==r) {t[u]=b[l]; return ;}
		build(ls,l,mid),build(rs,mid+1,r);
		t[u]=min(t[ls],t[rs]);
	}
	void pushdown(int u)
	{
		t[ls]+=tag[u],tag[ls]+=tag[u];
		t[rs]+=tag[u],tag[rs]+=tag[u];
		tag[u]=0;
	}
	void update(int u,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R) {t[u]+=v,tag[u]+=v; return ;}
		pushdown(u);
		if(mid>=L) update(ls,l,mid,L,R,v);
		if(mid<R) update(rs,mid+1,r,L,R,v);
		t[u]=min(t[ls],t[rs]);
	}
	int qry() {return t[1];}
}smt;
void work()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) l[i]=r[i]=b[i]=0;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(!a[i]);
	lim=sum[n]/2,cnt=0;
	for(int i=1;i<=n;i++) op[i]=sum[i]>lim;
	for(int i=1;i<=n;i++)
	{
		if(a[i]&&!op[i]) l[a[i]]=i;
		if(a[i]&&op[i]&&!r[a[i]]) r[a[i]]=i;
	}
	for(int i=1;i<=n;i++) if(l[i]||r[i]) cnt++;
	int siz=1; for(int i=1;i<=n;i++) if(op[i]&&!a[i]) siz++;
	for(int i=1;i<=n;i++)
	{
		if(!l[i]&&r[i]) b[sum[r[i]]+2-lim]++;
		else if(l[i]) b[1]++;
	}
	for(int i=1;i<=n;i++) b[i]+=b[i-1];
	for(int i=1;i<=siz;i++) b[i]+=siz-i;
	// for(int i=1;i<=siz;i++) printf("%d%c",b[i]," \n"[i==siz]);
	smt.build(1,1,siz);
	int ans=min(lim,smt.qry()),cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(op[i]) break;
		if(!a[i]) cnt++;
		if(a[i]&&l[a[i]]==i)
		{
			if(r[a[i]]) smt.update(1,1,siz,1,sum[r[a[i]]]+1-lim,-1);
			else smt.update(1,1,siz,1,siz,-1);
		}
		ans=min(ans,smt.qry()+cnt);
	}
	printf("%d\n",ans);
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}