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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 500005
struct BIT
{
	int len,t[N];
	void init(int l){len=l; for(int i=1;i<=len;i++) t[i]=0;}
	inline int lowbit(int x){return x&(-x);}
	void update(int u,int v){for(int i=u;i<=len;i+=lowbit(i)) t[i]+=v;}
	int query(int u)
	{
		int ans=0;
		for(int i=u;i>0;i-=lowbit(i)) ans+=t[i];
		return ans;
	}
}bit;
int a[N],rev[N],c[N],v[N],n;
void work()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),rev[a[i]]=i;
	int inv=0;
	bit.init(n);
	for(int i=1;i<=n;i++)
	{
		int r=bit.query(a[i]);
		c[i]=i-1-r-r;
		bit.update(a[i],1);
	}
	bit.init(n);
	for(int i=n;i>=1;i--)
	{
		inv+=bit.query(a[i]),c[i]-=2*bit.query(a[i]);
		bit.update(a[i],1);
	}
	// for(int i=1;i<=n;i++) printf("%d%c",c[i]," \n"[i==n]);
	sort(c+1,c+n+1,greater<int>());
	for(int i=0;i<=n;i++)
	{
		inv-=c[i];
		printf("%lld%c",inv-(i-1)*i/2," \n"[i==n]);
	}
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}