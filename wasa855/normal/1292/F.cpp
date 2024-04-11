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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 65
int a[N],n;
bool hav[N];
int fa[N];
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
int fac[N],inv[N],pinv[N];
void init()
{
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<N;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	pinv[0]=1; for(int i=1;i<N;i++) pinv[i]=mul(pinv[i-1],inv[i]);
}
int C(int x,int y){return x>=y?mul(fac[x],pinv[x-y],pinv[y]):0;}
pii solve(vector<int> v)
{
	if(v.size()==1) return {0,1};
	int n=v.size();
	sort(v.begin(),v.end());
	vector<int> dgr(n);
	for(int i=0;i<(int)v.size();i++)
	{
		for(int j=i+1;j<(int)v.size();j++)
		{
			if(v[j]%v[i]==0) dgr[j]++;
		}
	}
	vector<int> S,T;
	for(int i=0;i<(int)v.size();i++)
	{
		if(!dgr[i]) S.pb(v[i]);
		else T.pb(v[i]);
	}
	int cs=S.size(),ct=T.size();
	// printf("-- %d %d\n",cs,ct);
	vector<int> val(ct),cnt(1<<cs);
	for(int i=0;i<ct;i++)
	{
		for(int j=0;j<cs;j++)
		{
			if(T[i]%S[j]==0) val[i]|=1<<j;
		}
	}
	for(int i=0;i<ct;i++) cnt[val[i]]++;
	for(int i=0;i<cs;i++)
	{
		for(int j=0;j<1<<cs;j++)
		{
			if(j>>i&1) cnt[j]+=cnt[j^(1<<i)];
		}
	}
	// for(int i=0;i<ct;i++) printf("%d%c",val[i]," \n"[i==ct-1]);
	vector<vector<int>> f(1<<cs);
	for(int i=0;i<1<<cs;i++) f[i].resize(ct+1);
	for(int i=0;i<ct;i++) f[val[i]][0]++;
	for(int i=0;i<1<<cs;i++)
	{
		for(int j=0;j<ct;j++)
		{
			for(int k=0;k<ct;k++)
			{
				if((i|val[k])==i) continue;
				if(!(val[k]&i)) continue;
				f[i|val[k]][j+1]=add(f[i|val[k]][j+1],f[i][j]);
			}
			if(j!=ct) f[i][j+1]=add(f[i][j+1],mul(f[i][j],cnt[i]-j-1));
		}
	}
	return mp(ct-1,f[(1<<cs)-1][ct-1]);
}
signed main()
{
	init();
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read(),hav[a[i]]=1;
	int m=60;
	for(int i=1;i<=m;i++) if(hav[i]) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		if(!hav[i]) continue;
		for(int j=i+i;j<=m;j+=i)
		{
			if(!hav[j]) continue;
			fa[find(i)]=find(j);
		}
	}
	int sum=0,ans=1;
	for(int i=1;i<=m;i++)
	{
		if(find(i)==i)
		{
			vector<int> v;
			for(int j=1;j<=m;j++) if(find(j)==i) v.pb(j);
			auto [cnt,val]=solve(v);
			// printf("%d %d\n",cnt,val);
			sum+=cnt;
			ans=mul(ans,val,C(sum,cnt));
		}
	}
	cout<<ans<<endl;
	return 0;
}