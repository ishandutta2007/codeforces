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
#define int long long
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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%lld%c",x[i]," \n"[i==(int)x.size()-1]);}
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
#define inc(x,y) x=add((x),(y))
const int i2=(mod+1)/2;
#define N 4005
int a[N],b[N],f[2][2][N],g[2][2][N],n,p,c;
char s[N];
signed main()
{
	cin>>p>>c; scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;i++) a[i]=s[n-i+1]-'0';
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<N;j++) b[j]*=10;
		b[1]+=a[i];
		for(int j=1;j+1<N;j++) b[j+1]+=b[j]/p,b[j]%=p;
	}
	for(int i=1;i<N;i++) a[i]=b[i];
	n=N-1; while(n&&!a[n]) n--;
	// for(int i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	if(!n) {cout<<"0\n"; return 0;}
	f[1][0][0]=1;
	for(int i=n;i>=1;i--)
	{
		int _a=mul(p,p+1,i2),b=mul(p,p-1,i2),c=mul(a[i],a[i]+1,i2),d=mul(a[i],a[i]-1,i2),e=mul(a[i],p+p-a[i]-1,i2),_f=mul(a[i],p+p-a[i]+1,i2);
		memset(g,0,sizeof(g));
		for(int j=0;j<=n-i;j++)
		{
			inc(g[0][0][j],mul(f[0][0][j],_a));
			inc(g[0][0][j],mul(f[1][0][j],c));
			inc(g[0][1][j],mul(f[0][0][j],b));
			inc(g[0][1][j],mul(f[1][0][j],d));
			inc(g[1][0][j],mul(f[1][0][j],a[i]+1));
			inc(g[1][1][j],mul(f[1][0][j],a[i]));
			inc(g[0][0][j+1],mul(f[0][1][j],b));
			inc(g[0][0][j+1],mul(f[1][1][j],e));
			inc(g[0][1][j+1],mul(f[0][1][j],_a));
			inc(g[0][1][j+1],mul(f[1][1][j],_f));
			inc(g[1][0][j+1],mul(f[1][1][j],p-a[i]-1));
			inc(g[1][1][j+1],mul(f[1][1][j],p-a[i]));
		}
		memcpy(f,g,sizeof(f));
		// for(int i=0;i<=n;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) printf("%lld%c",f[j][k][i]," \n"[j+k==2]);
		// cout<<"\n";
	}
	int ans=0;
	for(int i=c;i<=n;i++) ans=add(ans,f[0][0][i],f[1][0][i]);
	cout<<ans<<endl;
	return 0;
}