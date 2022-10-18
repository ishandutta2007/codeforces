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
#define INF ((1LL<<60)-1)
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
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
int Inv(int x){return qpow(x,mod-2);}
#define N 105
vector<pii> Merge(vector<pii> a)
{
	int n=a.size(); for(int i=0;i<(int)a.size();i++) a[i].sec++;
	vector<int> t(n*2),v(n*2);
	for(int i=0;i<(int)a.size();i++) t[i*2]=a[i].fir,t[i*2+1]=a[i].sec;
	sort(t.begin(),t.end()); t.erase(unique(t.begin(),t.end()),t.end());
	for(int i=0;i<(int)a.size();i++) a[i].fir=lower_bound(t.begin(),t.end(),a[i].fir)-t.begin();
	for(int i=0;i<(int)a.size();i++) a[i].sec=lower_bound(t.begin(),t.end(),a[i].sec)-t.begin();
	for(int i=0;i<(int)a.size();i++) v[a[i].fir]++,v[a[i].sec]--;
	for(int i=1;i<(int)t.size();i++) v[i]+=v[i-1];
	vector<pii> ans;
	for(int i=0;i<(int)t.size();i++)
	{
		if(!v[i]) continue;
		int r=i; while(v[r]) r++;
		ans.eb(t[i],t[r]-1);
		i=r;
	}
	return ans;
}
vector<pii> a,b;
int n,m,I=Inv(2);
struct Node
{
	int v,ls,rs;
};
Node t[N*1005];
int cnt,rtA,rtB;
void build(int &u,int l,int r,int L,int R)
{
	if(!u) u=++cnt;
	// printf("%lld %lld %lld\n",u,l,r);
	if(L<=l&&r<=R) {t[u].v=1; return ;}
	int mid=(l+r)/2;
	if(mid>=L) build(t[u].ls,l,mid,L,R);
	if(mid<R) build(t[u].rs,mid+1,r,L,R);
}
int ans=0;
void query(vector<pii> q,int l,int r)
{
	if(q.empty()) return ;
	// printf("%lld %lld - ",l,r);
	// for(auto [u,v]:q) printf("%lld %lld + ",u,v);
	// cout<<"\n";
	for(auto [u,v]:q)
	{
		if(t[u].v||t[v].v)
		{
			// printf("* %lld %lld\n",l,r);
			ans=add(ans,mul((r-l+1)%mod,(l+r)%mod,I));
			return ;
		}
	}
	int mid=(l+r)/2;
	vector<pii> q1,q2;
	for(auto [u,v]:q)
	{
		if(t[u].ls&&t[v].ls) q1.eb(t[u].ls,t[v].ls);
		if(t[u].rs&&t[v].rs) q1.eb(t[u].rs,t[v].rs);
		if(t[u].rs&&t[v].ls) q2.eb(t[u].rs,t[v].ls);
		if(t[u].ls&&t[v].rs) q2.eb(t[u].ls,t[v].rs);
	}
	query(q1,l,mid),query(q2,mid+1,r);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) {int l=read(),r=read(); a.eb(l,r);}
	cin>>m;
	for(int i=1;i<=m;i++) {int l=read(),r=read(); b.eb(l,r);}
	a=Merge(a),b=Merge(b);
	// for(auto [l,r]:a) printf("%d %d\n",l,r);
	// for(auto [l,r]:b) printf("%d %d\n",l,r);
	for(auto [l,r]:a) build(rtA,0,INF,l,r);
	// cout<<"\n";
	for(auto [l,r]:b) build(rtB,0,INF,l,r);
	// cout<<"\n";
	query({mp(rtA,rtB)},0,INF);
	cout<<ans<<endl;
	return 0;
}