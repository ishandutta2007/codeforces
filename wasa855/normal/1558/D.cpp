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
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
#define N 400005
int fac[N],inv[N],ifac[N];
void init()
{
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<N;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	ifac[0]=1; for(int i=1;i<N;i++) ifac[i]=mul(ifac[i-1],inv[i]);
}
int C(int x,int y){return x>=y?mul(fac[x],ifac[x-y],ifac[y]):0;}
struct BIT
{
	int len,t[N];
	void init(int l){len=l,memset(t,0,sizeof(t));}
	inline int lowbit(int x){return x&(-x);}
	void update(int u,int v){for(int i=u;i<=len;i+=lowbit(i)) t[i]+=v;}
	int query(int u)
	{
		int ans=0;
		for(int i=u;i>0;i-=lowbit(i)) ans+=t[i];
		return ans;
	}
}bit;
int x[N],y[N],pos[N],tim[N];
void work()
{
	int n=read(),m=read();
	for(int i=1;i<=m;i++) x[i]=read(),y[i]=read();
	for(int i=m;i>=1;i--)
	{
		int l=1,r=n,ans;
		while(l<=r)
		{
			int mid=((l+r)/2);
			if(bit.query(mid)>=y[i]) ans=mid,r=mid-1;
			else l=mid+1;
		}
		pos[i]=ans,bit.update(pos[i],-1);
	}
	for(int i=1;i<=m;i++) tim[pos[i]]=i;
	// for(int i=1;i<=m;i++) printf("%d%c",pos[i]," \n"[i==m]);
	int res=m;
	for(int i=1;i<=m;i++) if(tim[pos[i]-1]&&tim[pos[i]-1]<i) res--;
	// cout<<res<<endl;
	// res=res+n-m-1;
	// cout<<res<<endl;
	printf("%d\n",C(2*n-res-1,n));
	for(int i=1;i<=m;i++) tim[pos[i]]=0;
	for(int i=1;i<=m;i++) bit.update(pos[i],1);
}
signed main()
{
	init(); bit.init(200000);
	for(int i=1;i<=200000;i++) bit.update(i,1);
	int T=read(); while(T--) work();
	return 0;
}