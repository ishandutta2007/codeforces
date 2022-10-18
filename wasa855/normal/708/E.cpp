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
inline int add(int a,int b,int c,int d){return add(a,b,add(c,d));};
inline int mul(int a,int b,int c,int d){return mul(a,b,mul(c,d));};
inline int add(int a,int b,int c,int d,int e){return add(a,b,c,add(d,e));}
inline int mul(int a,int b,int c,int d,int e){return mul(a,b,c,mul(d,e));}
#define N 1505
#define M 100005
int fac[M],inv[M],pinv[M];
void init()
{
	fac[0]=1; for(int i=1;i<M;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<M;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	pinv[0]=1; for(int i=1;i<M;i++) pinv[i]=mul(pinv[i-1],inv[i]);
}
int C(int x,int y){return x>=y?mul(fac[x],pinv[x-y],pinv[y]):0;}
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
int n,m,a,b,k,P;
int D[N],dp[N][N],s[N][N],ss[N][N],sp[N];
signed main()
{
	init();
	cin>>n>>m>>a>>b>>k; P=mul(a,Inv(b));
	for(int i=0;i<=min(m,k);i++) D[i]=mul(C(k,i),qpow(P,i),qpow(mod+1-P,k-i));
	for(int i=1;i<=m;i++) for(int j=0;j<i;j++) sp[i]=add(sp[i],mul(D[j],D[m-i]));
	// for(int i=1;i<=m;i++) printf("%d ",sp[i]); cout<<"\n";
	dp[0][m]=1; s[0][m]=1; // ss[0][m]=mul(D[0],D[0]);
	// printf("%d %d %d %d\n",sp[2],s[0][2],s[0][0],ss[0][2]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) dp[i][j]=sub(mul(sp[j],sub(s[i-1][m],s[i-1][m-j])),ss[i-1][j]);
		for(int j=1;j<=m;j++) s[i][j]=add(s[i][j-1],dp[i][j]);
		for(int j=2;j<=m;j++) ss[i][j]=add(ss[i][j-1],mul(s[i][j-1],D[j-1]));
		for(int j=1;j<=m;j++) ss[i][j]=mul(ss[i][j],D[m-j]);
	}
	// for(int i=0;i<=n;i++)
	// {
		// for(int j=1;j<=m;j++) printf("%d ",dp[i][j]);
		// cout<<"\n";
	// }
	cout<<s[n][m]<<endl;
	return 0;
}