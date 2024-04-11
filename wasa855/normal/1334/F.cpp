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
#define N 500005
int a[N],b[N],c[N],p[N],sum[N];
int f[N],v[N],n,m;
int t[N];
int lowbit(int u){return u&(-u);}
void update(int u,int d){while(u<=n){t[u]+=d; u+=lowbit(u);}}
int query(int u){int ans=0;while(u){ans+=t[u]; u-=lowbit(u);} return ans;}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+p[i];
	cin>>m;
	for(int i=1;i<=m;i++) b[i]=read();
	for(int i=1;i<=m;i++) c[b[i]]=i;
	int cur=1;
	for(int i=1;i<=n;i++)
	{
		if(cur<=m&&a[i]==b[cur]) cur++;
	}
	if(cur<=m) {cout<<"NO\n"; return 0;}
	cout<<"YES\n";
	for(int i=1;i<=m;i++) f[i]=INF;
	for(int i=1;i<=n;i++)
	{
		if(c[a[i]])
		{
			int qaq=c[a[i]];
			v[i]=f[qaq-1]+sum[i-1]-query(b[qaq-1]);
			if(p[i]>0) update(a[i],p[i]);
			int R=v[i]-sum[i]+query(b[qaq]);
			if(R<f[qaq]) f[qaq]=R;
		}
		else if(p[i]>0) update(a[i],p[i]);
	}
	int res=0,ans=INF;
	for(int i=n;i>=1;i--)
	{
		if(a[i]==b[m])
		{
			if(v[i]+res<ans) ans=v[i]+res;
			if(p[i]<0) res+=p[i];
		}
		else if(a[i]>b[m]||p[i]<0) res+=p[i];
	}
	cout<<ans<<endl;
	return 0;
}