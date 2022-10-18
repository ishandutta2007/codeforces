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
#define N 5005
int b[N];
int n,q;
struct Node
{
	vector<int> v;
	map<pii,int> m;
};
Node a[N*4];
vector<pii> c;
int ans[N*20];
#define ls (u<<1)
#define rs (u<<1|1)
void build(int u,int l,int r)
{
	if(l==r) {a[u].v.pb(b[l]); return ;}
	int mid=(l+r)/2;
	build(ls,l,mid);
	build(rs,mid+1,r);
	int i=0,j=0;
	while(i<(int)a[ls].v.size()&&j<(int)a[rs].v.size())
	{
		if(a[ls].v[i]<a[rs].v[j]) a[u].v.pb(a[ls].v[i++]);
		else a[u].v.pb(a[rs].v[j++]);
	}
	while(i<(int)a[ls].v.size()) a[u].v.pb(a[ls].v[i++]);
	while(j<(int)a[rs].v.size()) a[u].v.pb(a[rs].v[j++]);
	// printf("-- %d %d %d ** %u %u\n",u,l,r,a[ls].v.size(),a[rs].v.size());
	// for(int i:a[u].v) printf("%d ",i); cout<<"\n";
}
int solve(int u,int L,int R)
{
	int l=lower_bound(a[u].v.begin(),a[u].v.end(),L)-a[u].v.begin();
	int r=upper_bound(a[u].v.begin(),a[u].v.end(),R)-a[u].v.begin();
	// printf("%d %d %d ** %d %d\n",u,L,R,l,r);
	if(l==(int)a[u].v.size()||l==r) return -1;
	if(l+1==r) return a[u].v[l];
	if(a[u].m[mp(l,r)]) return a[u].m[mp(l,r)];
	int x=solve(ls,L,R),y=solve(rs,L,R);
	if(x!=-1&&y!=-1)
	{
		c.eb(x,y);
		return a[u].m[mp(l,r)]=c.size()+n;
	}
	else return a[u].m[mp(l,r)]=max(x,y);
}
signed main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) b[read()]=i;
	build(1,1,n);
	for(int i=1;i<=q;i++)
	{
		int l=read(),r=read();
		ans[i]=solve(1,l,r);
	}
	cout<<c.size()+n<<endl;
	for(auto [x,y]:c) printf("%d %d\n",x,y);
	for(int i=1;i<=q;i++) printf("%d ",ans[i]);
	return 0;
}