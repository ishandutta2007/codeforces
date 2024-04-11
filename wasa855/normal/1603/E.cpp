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
int mod;
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
int n;
#define N 205
int f[N][N][N];
int fac[N],inv[N],ifac[N];
void init()
{
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<N;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	ifac[0]=1; for(int i=1;i<N;i++) ifac[i]=mul(ifac[i-1],inv[i]);
}
int solve(int mn)
{
	memset(f,0,sizeof(f));
	f[0][mn-1][0]=1;
	for(int j=mn;j<=n+1;j++)
	{
		for(int k=0;k<=j-1;k++)
		{
			for(int i=0;i+(n-k)*(j-mn)<=mn;i++) if(f[i][j-1][k])
			{
				// printf("%d %d %d\n",i,j,k);
				for(int g=0;k+g<=j&&i+(j-mn)*g<=min(mn,(j-k-g)*mn);g++)
				{
					if(j==n+1&&g==0) continue;
					// printf("^^ %d %d %d %d\n",i,j,k,g);
					f[i+(j-mn)*g][j][k+g]=add(f[i+(j-mn)*g][j][k+g],mul(f[i][j-1][k],ifac[g]));
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=mn;i++) ans=add(ans,f[i][n+1][n]);
	return mul(ans,fac[n]);
}
signed main()
{
	cin>>n>>mod; int ans=1;
	init();
	for(int i=max(1,n-17);i<=n;i++) ans=add(ans,solve(i));
	cout<<ans<<endl;
	return 0;
}