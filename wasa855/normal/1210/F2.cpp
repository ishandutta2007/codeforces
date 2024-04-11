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
#define mod 1000000007
#define ll __uint128_t
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
#define inc(x,y) x=add(x,y)
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
#define ull unsigned long long
const int i100=Inv(100);
map<ll,int> f[8];
vector<int> fv[8];
ll pw[128];
int cnt;
int ful,n,a[7][7],p[7][128];
ll tr[128][128];
int lowbit(int x) {return x&(-x);}
void init()
{
	for(int i=0;i<ful;i++)
	{
		for(int j=0;j<ful;j++)
		{
			ll gmp=0;
			for(int k=0;k<ful;k++)
			{
				int pr=j&k;
				while(pr)
				{
					int lw=lowbit(pr);
					if((k^lw)==i) {gmp|=pw[k]; break;}
					pr^=lw;
				}
			}
			tr[i][j]=gmp;
		}
	}
}
/*
int getid(ll st)
{
	if(id[st]) return id[st];
	id[st]=++cnt; int cur=cnt;
	for(int i=0;i<ful;i++)
	{
		ll tmp=st;
		for(int j=0;j<ful;j++) if(!(st>>j&1))
		{
			int pr=i&j;
			while(pr)
			{
				int lw=lowbit(pr);
				if(st>>(j^lw)&1) {tmp|=pw[j]; break;}
				pr^=lw;
			}
		}
		tr[cur][i]=getid(tmp);
	}
	return cur;
}
*/
void print(ll v) {for(int i=0;i<ful;i++) printf("%d",(int)(v>>i&1));}
signed main()
{
	pw[0]=1; for(int i=1;i<128;i++) pw[i]=pw[i-1]*2;
	cin>>n;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) a[i][j]=mul(read(),i100);
	ful=1<<n;
	for(int i=0;i<ful;i++) fv[__builtin_popcount(i)].pb(i);
	init();
//	cout<<cnt<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<ful;j++)
		{
			int cur=1;
			for(int k=0;k<n;k++)
			{
				if(j>>k&1) cur=mul(cur,a[k][i]);
				else cur=mul(cur,mod+1-a[k][i]);
			}
			p[i][j]=cur;
		}
	}
	f[0][1]=1;
	for(int i=0;i<n;i++)
	{
		for(auto it:f[i])
		{
			ll st=it.fir; int v=it.sec;
			vector<ll> id(ful);
			for(int k:fv[i]) if(st>>k&1)
			{
				for(int j=0;j<ful;j++) id[j]|=tr[k][j];
			}
			for(int j=0;j<ful;j++)
			{
				inc(f[i+1][id[j]],mul(v,p[i][j]));
			}
		}
		/*
		for(int j=1;j<=cnt;j++)
		{
			for(int k=0;k<ful;k++) inc(f[i+1][tr[j][k]],mul(f[i][j],p[i][k]));
		}
		*/
	}
	ll all=pw[ful-1];
	cout<<f[n][all]<<endl;
	return 0;
}