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
#define N 2005
char s[N][N],t[N][N];
int n,m;
int pw[N*N];
namespace sub1
{
	int vis[N],cur[N];
	void Main()
	{
		assert(n%2==0&&m%2==1);
		for(int i=1;i<n;i++) for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='?') vis[i]++;
			if(s[i][j]=='1') cur[i]^=1;
		}
		int fl=0,c=0;
		for(int j=1;j<=m;j++)
		{
			if(s[n][j]=='1') fl^=1;
			if(s[n][j]=='?') c++;
		}
		auto gv=[&](int cur,int c,int ned)
		{
			if(c) return pw[c-1];
			else if(cur==ned) return 1;
			else return 0;
		};
		int all=0;
		{// all 0
			int ans=gv(fl,c,0);
			for(int i=1;i<n;i++) ans=mul(ans,gv(cur[i],vis[i],0));
			// cout<<ans<<endl;
			all=add(all,ans);
		}
		{// all 1
			int ans=gv(fl,c,1);
			for(int i=1;i<n;i++) ans=mul(ans,gv(cur[i],vis[i],1));
			// cout<<ans<<endl;
			all=add(all,ans);
		}
		cout<<all<<endl;
	}
};
namespace sub2
{
	int fa[N*2],val[N*2],siz[N*2],esiz[N*2],sval[N*2];
	int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
	void merge(int u,int v) {fa[find(u)]=find(v);}
	void Main()
	{
		for(int i=1;i<=n+m;i++) fa[i]=i;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='1') val[i]^=1,val[j+n]^=1;
			if(s[i][j]=='?') merge(i,j+n);
		}
		for(int i=1;i<=n+m;i++) siz[find(i)]++,sval[find(i)]^=val[i];
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(s[i][j]=='?') esiz[find(i)]++;
		// for(int i=1;i<=n+m;i++) if(find(i)==i) printf("%d %d %d\n",siz[i],sval[i],esiz[i]);
		int all=0;
		{ // all 0
			int ans=1;
			for(int i=1;i<=n+m;i++) if(find(i)==i)
			{
				if(siz[i]&1)
				{
					if(sval[i]) ans=mul(ans,pw[esiz[i]-siz[i]+1]);
					else ans=0;
				}
				else
				{
					if(sval[i]) ans=0;
					else ans=mul(ans,pw[esiz[i]-siz[i]+1]);
				}
			}
			all=add(all,ans);
		}
		{ // all 1
			int ans=1;
			for(int i=1;i<=n+m;i++) if(find(i)==i)
			{
				if(siz[i]&1)
				{
					if(!sval[i]) ans=mul(ans,pw[esiz[i]-siz[i]+1]);
					else ans=0;
				}
				else
				{
					if(sval[i]) ans=0;
					else ans=mul(ans,pw[esiz[i]-siz[i]+1]);
				}
			}
			all=add(all,ans);
		}
		cout<<all<<endl;
	}
};
signed main()
{
	cin>>n>>m;
	pw[0]=1; for(int i=1;i<N*N;i++) pw[i]=mul(pw[i-1],2);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	if(n%2==0&&m%2==0)
	{
		int q=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) q+=s[i][j]=='?';
		cout<<qpow(2,q)<<endl;
	}
	else if(n%2==0&&m%2==1) sub1::Main();
	else if(n%2==1&&m%2==0)
	{
		memcpy(t,s,sizeof(t));
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s[j][i]=t[i][j];
		swap(n,m);
		sub1::Main();
	}
	else sub2::Main();
	return 0;
}