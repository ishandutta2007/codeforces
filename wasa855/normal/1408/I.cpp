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
#define ull unsigned long long
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
inline int mul(int x,int y) {return 1ULL*x*y%mod;}
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
#define N 65536
int a[N],C[25][25],ans[N],v[N],id[N],n,k,c;
ull f[N/2][20];
signed main()
{
	cin>>n>>k>>c;
	for(int i=1;i<=n;i++) a[i]=read();
	C[0][0]=1;
	for(int i=1;i<25;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++) C[i][j]=add(C[i-1][j-1],C[i-1][j]);
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=k;j++) v[i]=max(v[i],a[i]^(a[i]-j));
	for(int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,[&](int x,int y){return v[x]<v[y];});
	f[0][0]=1; int pw=0;
	for(int d=1;d<=n;d++)
	{
		int val=a[id[d]];
		while(1<<pw<=(v[id[d]]/2)) pw++;
		for(int i=k-1;i>=0;i--) for(int j=0;j<1<<pw;j++)
		{
			for(int c=1;c<=k-i;c++) f[j^((val^(val-c))/2)][i+c]+=f[j][i]*C[k-i][c];
		}
		for(int j=0;j<1<<pw;j++) for(int i=0;i<=k;i++) f[j][i]%=mod;
	}
	int sum=0;
	for(int i=1;i<=n;i++) sum^=a[i];
	for(int i=0;i<1<<pw;i++) ans[(i*2)^sum^(k&1)]+=f[i][k];
	int ipw=Inv(qpow(n,k));
	for(int i=0;i<1<<c;i++) printf("%d%c",mul(ans[i],ipw)," \n"[i==(1<<c)-1]);
	return 0;
}