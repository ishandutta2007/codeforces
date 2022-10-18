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
#define N 500005
#define M 10000005
bool vis[M];
int p[M],f[M],a[N],x[N],y[N],cnt,n;
void init()
{
	for(int i=2;i<M;i++)
	{
		if(!vis[i])
		{
			p[++cnt]=i;
			f[i]=i;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(i*p[j]>=M) break;
			vis[i*p[j]]=1;
			f[i*p[j]]=min(f[i],p[j]);
			if(i%p[j]==0) break;
		}
	}
}
signed main()
{
	init();
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		int A=f[a[i]],r=a[i];
		while(a[i]%A==0) a[i]/=A;
		if(a[i]==1) continue;
		if(__gcd(A+a[i],r)==1) x[i]=A,y[i]=a[i];
	}
	for(int i=1;i<=n;i++) printf("%d ",x[i]==0?-1:x[i]); cout<<"\n";
	for(int i=1;i<=n;i++) printf("%d ",y[i]==0?-1:y[i]); cout<<"\n";
	return 0;
}