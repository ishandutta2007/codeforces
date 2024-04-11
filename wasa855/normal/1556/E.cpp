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
#define int long long
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
#define abs sahfhs
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%lld%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 100005
int a[N],b[N],sum[N],n,Q;
struct Node{int sum,mn,mx;};
Node merge(Node x,Node y)
{
	return (Node){x.sum+y.sum,min(x.mn,x.sum+y.mn),max(x.mx,x.sum+y.mx)};
}
int l[N],r[N],ans[N];
struct SMT
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	Node t[N*4];
	void build(int u,int l,int r)
	{
		if(l==r)
		{
			t[u]=(Node){a[l],a[l],a[l]};
			return ;
		}
		build(ls,l,mid),build(rs,mid+1,r);
		t[u]=merge(t[ls],t[rs]);
	}
	Node query(int u,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return t[u];
		if(mid>=L&&mid<R) return merge(query(ls,l,mid,L,R),query(rs,mid+1,r,L,R));
		else if(mid>=L) return query(ls,l,mid,L,R);
		else return query(rs,mid+1,r,L,R);
	}
}smt;
signed main()
{
	cin>>n>>Q;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	for(int i=1;i<=n;i++) a[i]=a[i]-b[i];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	for(int i=1;i<=Q;i++) l[i]=read(),r[i]=read();
	smt.build(1,1,n);
	for(int i=1;i<=Q;i++)
	{
		Node res=smt.query(1,1,n,l[i],r[i]);
		if(res.sum!=0) ans[i]=INF;
		if(res.mx>0) ans[i]=INF;
		ans[i]=max(ans[i],-res.mn);
	}
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++) a[i]=-a[i];
	for(int i=1;i<=Q;i++) l[i]=n-l[i]+1,r[i]=n-r[i]+1,swap(l[i],r[i]);
	smt.build(1,1,n);
	for(int i=1;i<=Q;i++)
	{
		Node res=smt.query(1,1,n,l[i],r[i]);
		if(res.sum!=0) ans[i]=INF;
		if(res.mx>0) ans[i]=INF;
		ans[i]=max(ans[i],-res.mn);
	}
	for(int i=1;i<=Q;i++)
	{
		if(ans[i]==INF) printf("-1\n");
		else printf("%lld\n",ans[i]);
	}
	return 0;
}