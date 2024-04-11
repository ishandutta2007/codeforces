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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1uLL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
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
#define N 3005
namespace QAQ
{
	int f[N][N],a[N],cnt[N],pw[N],ipw[N],ans[N];
	int qwq[N],qaq[N];
	void Main(int n,int c)
	{
		for(int i=1;i<=n;i++) a[i]=read();
		f[0][0]=1;
		pw[0]=1; for(int i=1;i<N;i++) pw[i]=mul(pw[i-1],2);
		for(int i=0;i<N;i++) pw[i]=sub(pw[i],1);
		for(int i=0;i<N;i++) ipw[i]=Inv(pw[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i/c;j++)
			{
				int x=0,ans=1;
				for(int k=i;k>=1;k--)
				{
					if(a[k]==a[i])
					{
						if(x==c-1) f[i][j]=add(f[i][j],mul(ans,f[k-1][j-1]));
						continue;
					}
					if(!cnt[a[k]]) x++;
					else ans=mul(ans,ipw[cnt[a[k]]]);
					cnt[a[k]]++;
					ans=mul(ans,pw[cnt[a[k]]]);
					if(x==c-1) f[i][j]=add(f[i][j],mul(ans,f[k-1][j-1]));
				}
				for(int k=i;k>=1;k--) if(a[k]!=a[i]) cnt[a[k]]--;
			}
		}
		// for(int i=1;i<=n;i++)
		// {
			// for(int j=1;j<=n;j++) printf("%d%c",f[i][j]," \n"[j==n]);
		// }
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++) cnt[a[j]]++;
			int tmp=pw[n-i]+1,res=1;
			for(int j=1;j<=c;j++)
			{
				if(!cnt[j]) res=0;
				else res=mul(res,pw[cnt[j]]);
			}
			tmp=sub(tmp,res);
			for(int j=1;j<=n;j++) ans[j]=add(ans[j],mul(tmp,f[i][j]));
			for(int j=i+1;j<=n;j++) cnt[a[j]]--;
		}
		ans[0]=pw[n];
		for(int i=1;i<=n;i++) ans[0]=sub(ans[0],ans[i]);
		for(int i=0;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	}
};
namespace QWQ
{
	const int S=12;
	int f[N][1<<S],g[N][1<<S],a[N];
	void Main(int n,int c)
	{
		for(int i=1;i<=n;i++) a[i]=read()-1;
		f[0][0]=1;
		int lim=(1<<c)-1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=i/c;j++)
			{
				for(int k=0;k<(1<<c);k++) g[j][k]=0;
			}
			for(int j=0;j<=i/c;j++)
			{
				for(int k=0;k<(1<<c);k++)
				{
					if((k|(1<<a[i]))==lim) g[j+1][0]=add(g[j+1][0],f[j][k]);
					else g[j][k|(1<<a[i])]=add(g[j][k|(1<<a[i])],f[j][k]);
					g[j][k]=add(g[j][k],f[j][k]);
				}
			}
			for(int j=0;j<=i/c;j++)
			{
				for(int k=0;k<(1<<c);k++) f[j][k]=g[j][k];
			}
		}
		for(int i=0;i<=n;i++)
		{
			int ans=0;
			for(int j=0;j<=lim;j++) ans=add(ans,g[i][j]);
			if(i==0) ans=sub(ans,1);
			printf("%d%c",ans," \n"[i==n]);
		}
	}
};
signed main()
{
	int n,c; cin>>n>>c;
	if(c>=13) QAQ::Main(n,c);
	else QWQ::Main(n,c);
	return 0;
}