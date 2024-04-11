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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
#define N 8005
int fac[N],inv[N],ifac[N];
void init()
{
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<N;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	ifac[0]=1; for(int i=1;i<N;i++) ifac[i]=mul(ifac[i-1],inv[i]);
}
int C(int x,int y){return x>=y?mul(fac[x],ifac[x-y],ifac[y]):0;}
vector<int> G[N];
int n;
pair<vector<int>,vector<int>> dfs(int u,int fa)
{
	vector<int> f={0,1},g={0,1};
	for(int v:G[u]) if(v!=fa)
	{
		auto _=dfs(v,u);
		const vector<int> &tf=_.fir,&tg=_.sec;
		vector<int> rf(f.size()+tf.size()-1),rg(f.size()+tf.size()-1);
		for(int i=1;i<(int)f.size();i++) for(int j=1;j<(int)tf.size();j++)
		{
			rf[i+j]=add(rf[i+j],mul(f[i],tg[j]));
			rg[i+j]=add(rg[i+j],mul(g[i],tg[j]));
			rf[i+j-1]=add(rf[i+j-1],mul(f[i],tf[j]));
			rg[i+j-1]=add(rg[i+j-1],mul(f[i],tg[j]));
			rg[i+j-1]=add(rg[i+j-1],mul(g[i],tf[j]));
		}
		f=rf,g=rg;
	}
	return {f,g};
}
int ans[N];
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	auto _=dfs(1,0); vector<int> tmp=_.sec;
	tmp[1]=1; int prd=1;
	for(int i=2;i<(int)tmp.size();i++) tmp[i]=mul(tmp[i],prd),prd=mul(prd,n);
	for(int i=1;i<=n;i++) ans[n-i]=tmp[i];
//	for(int i=0;i<n;i++) printf("%d%c",ans[i]," \n"[i==n-1]);
	init();
	for(int i=n-1;i>=0;i--)
	{
		for(int j=i+1;j<n;j++) ans[i]=sub(ans[i],mul(ans[j],C(j,i)));
	}
	for(int i=0;i<n;i++) printf("%d%c",ans[i]," \n"[i==n-1]);
	return 0;
}