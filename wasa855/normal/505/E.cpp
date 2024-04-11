#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 100005
int h[N],a[N],Cnt[N];
int n,m,k,p;
struct Node
{
	int r,id;
	bool operator < (const Node &x) const
	{
		return r>x.r;
	}
};
bool judge(int mid)
{
	for(int i=1;i<=n;i++) Cnt[i]=0;
	priority_queue<Node> q;
	for(int i=1;i<=n;i++)
	{
		int ned=mid/a[i];
		if(ned<m) q.push((Node){ned,i});
	}
	int r=1,cnt=0;
	while(!q.empty())
	{
		if(cnt==k) r++,cnt=0;
		if(r>m) return 0;
		Node u=q.top(); q.pop();
		cnt++;
		if(u.r<r) return 0;
		Cnt[u.id]++;
		int ned=(mid+Cnt[u.id]*p)/a[u.id];
		if(ned<m) q.push((Node){ned+1,u.id});
	}
	int res=(m-r+1)*k-cnt;
	for(int i=1;i<=n;i++)
	{
		int R=mid+Cnt[i]*p-m*a[i];
		if(R>=h[i]) continue;
		int ned=(h[i]-R)/p;
		if((h[i]-R)%p) ned++;
		res-=ned;
		if(res<0) return 0;
	}
	return 1;
}
signed main()
{
	cin>>n>>m>>k>>p;
	for(int i=1;i<=n;i++) h[i]=read(),a[i]=read();
	int l=0,r=0,ans;
	for(int i=1;i<=n;i++) if(a[i]>l) l=a[i];
	for(int i=1;i<=n;i++) if(h[i]+a[i]*m*k>r) r=h[i]+a[i]*m*k;
	while(l<=r)
	{
		int  mid=(l+r)/2;
		if(judge(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
	return 0;
}