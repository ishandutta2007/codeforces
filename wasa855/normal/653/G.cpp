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
#define N 1000005
int fac[N],inv[N],ifac[N],pw[N];
void init()
{
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<N;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	ifac[0]=1; for(int i=1;i<N;i++) ifac[i]=mul(ifac[i-1],inv[i]);
	pw[0]=1; for(int i=1;i<N;i++) pw[i]=add(pw[i-1],pw[i-1]);
}
int C(int x,int y){return x>=y?mul(fac[x],ifac[x-y],ifac[y]):0;}
int pr[N],vis[N],mu[N],cnt;
void sieve()
{
	mu[1]=1; int n=N-5;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) mu[i]=-1,pr[++cnt]=i;
		for(int j=1;j<=cnt&&i*pr[j]<=n;j++)
		{
			vis[i*pr[j]]=1;
			if(i%pr[j]==0) break;
			mu[i*pr[j]]=-mu[i];
		}
	}
}
int getid(int p) {return lower_bound(pr+1,pr+cnt+1,p)-pr;}
int a[N],n;
int pop[N/10][21];
int getsuf(int v,int k)
{
	int res=pw[v];
	for(int i=0;i<k;i++) res=sub(res,C(v,i));
	return res;
}
int pre[21],suf[21];
int solve(int a[],int maxn)
{
	memset(pre,0,sizeof(pre));
	memset(suf,0,sizeof(suf));
	pre[0]=a[0]; for(int i=1;i<=maxn;i++) pre[i]=pre[i-1]+a[i];
	suf[maxn]=a[maxn]; for(int i=maxn-1;i>=0;i--) suf[i]=suf[i+1]+a[i];
	int ans=0;
	for(int i=0;i<maxn;i++)
	{
		int s1=pre[i],s2=suf[i+1];
		int res=pw[s2];
		for(int j=0;j<=s2;j++)
		{
			res=sub(res,C(s2,j));
			ans=add(ans,mul(j,C(s1,j),res));
		}
		res=pw[s1];
		for(int j=0;j<=s2;j++)
		{
			ans=add(ans,mul(j,C(s2,j),res));
			res=sub(res,C(s1,j));
		}
	}
	return ans;
}
signed main()
{
	sieve(),init(); cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=cnt&&pr[j]*pr[j]<=a[i];j++)
		{
			if(a[i]%pr[j]==0)
			{
				int res=0;
				while(a[i]%pr[j]==0) a[i]/=pr[j],res++;
				pop[j][res]++;
			}
		}
		if(a[i]!=1) pop[getid(a[i])][1]++;
	}
	int ans=0;
	for(int i=1;i<=cnt;i++)
	{
		int sum=0,maxn=0;
		for(int j=1;j<=20;j++) if(pop[i][j]) maxn=j,sum+=pop[i][j];
		pop[i][0]=n-sum;
		if(maxn) ans=add(ans,solve(pop[i],maxn));
	}
	cout<<ans<<endl;
	return 0;
}