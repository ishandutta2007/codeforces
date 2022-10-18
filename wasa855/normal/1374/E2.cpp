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
#define lim 10000
#define ll long long
#define inf 0x7fffffff
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 200005
int t[N],a[N],b[N];
int n,m,k;
vector<pii> v[2][2];
struct Smt
{
#define ls (u<<1)
#define rs (u<<1|1)
	int siz[N*4],sum[N*4];
	void pushup(int u)
	{
		siz[u]=siz[ls]+siz[rs];
		sum[u]=sum[ls]+sum[rs];
	}
	void insert(int u,int l,int r,int v,int d)
	{
		// if(l==1&&r==lim) printf("-- %d %d\n",v,d);
		if(l==r) {sum[u]+=d*v,siz[u]+=d; return ;}
		int mid=(l+r)/2;
		if(v<=mid) insert(ls,l,mid,v,d);
		else insert(rs,mid+1,r,v,d);
		siz[u]+=d,sum[u]+=d*v;
	}
	int query(int u,int l,int r,int v)
	{
		if(!v) return 0;
		if(v>siz[u]) return inf;
		if(siz[u]==v) return sum[u];
		if(l==r)
		{
			if(siz[u]>=v) return l*v;
			else return inf;
		}
		int mid=(l+r)/2;
		if(siz[ls]<=v) return sum[ls]+query(rs,mid+1,r,v-siz[ls]);
		else return query(ls,l,mid,v);
	}
#undef ls
#undef rs
};
Smt smt;
signed main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) t[i]=read(),a[i]=read(),b[i]=read();
	for(int i=1;i<=n;i++) v[a[i]][b[i]].eb(t[i],i);
	for(int i=0;i<2;i++) for(int j=0;j<2;j++) sort(v[i][j].begin(),v[i][j].end());
	int tmp=0;
	for(int i=0;i<min((int)v[1][1].size(),k);i++) tmp+=v[1][1][i].fir;
	int ned=k-min((int)v[1][1].size(),k);
	if((int)min(v[0][1].size(),v[1][0].size())<ned) {cout<<"-1\n"; return 0;}
	if(min((int)v[1][1].size(),k)+ned+ned>m) {cout<<"-1\n"; return 0;}
	for(int i=0;i<ned;i++) tmp+=v[0][1][i].fir+v[1][0][i].fir;
	for(int i=0;i<(int)v[0][0].size();i++) smt.insert(1,1,lim,v[0][0][i].fir,1);
	for(int i=ned;i<(int)v[0][1].size();i++) smt.insert(1,1,lim,v[0][1][i].fir,1);
	for(int i=ned;i<(int)v[1][0].size();i++) smt.insert(1,1,lim,v[1][0][i].fir,1);
	for(int i=k;i<(int)v[1][1].size();i++) smt.insert(1,1,lim,v[1][1][i].fir,1);
	int ans=inf,res=inf;
	for(int i=min((int)v[1][1].size(),k)-1;i>=-1;i--)
	{
		int x=m-i-1-(k-i-1)*2;
		int R;
		if(x>=0) R=tmp+smt.query(1,1,lim,x);
		else R=inf;
		// printf("%d %d %d %d\n",i,x,R,tmp);
		if(R<ans) ans=R,res=i+1;
		if(i==-1) break;
		tmp-=v[1][1][i].fir;
		int cned=k-i-1;
		if((int)v[0][1].size()<=cned) break;
		if((int)v[1][0].size()<=cned) break;
		tmp+=v[0][1][cned].fir+v[1][0][cned].fir;
		smt.insert(1,1,lim,v[0][1][cned].fir,-1);
		smt.insert(1,1,lim,v[1][0][cned].fir,-1);
		smt.insert(1,1,lim,v[1][1][i].fir,1);
	}
	if(ans==inf) {cout<<"-1\n"; return 0;}
	cout<<ans<<endl;
	vector<int> Ans; ned=k-res;
	vector<pii> Tmp;
	for(int i=0;i<res;i++) Ans.pb(v[1][1][i].sec);
	for(int i=res;i<(int)v[1][1].size();i++) Tmp.eb(v[1][1][i].fir,v[1][1][i].sec);
	for(int i=0;i<ned;i++) Ans.pb(v[0][1][i].sec);
	for(int i=ned;i<(int)v[0][1].size();i++) Tmp.eb(v[0][1][i].fir,v[0][1][i].sec);
	for(int i=0;i<ned;i++) Ans.pb(v[1][0][i].sec);
	for(int i=ned;i<(int)v[1][0].size();i++) Tmp.eb(v[1][0][i].fir,v[1][0][i].sec);
	for(int i=0;i<(int)v[0][0].size();i++) Tmp.eb(v[0][0][i].fir,v[0][0][i].sec);
	sort(Tmp.begin(),Tmp.end());
	for(int i=0;i<m-res-ned-ned;i++) Ans.pb(Tmp[i].sec);
	for(int i:Ans) printf("%d ",i);
	return 0;
}