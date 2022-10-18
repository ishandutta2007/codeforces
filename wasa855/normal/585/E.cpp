#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 10000005
int a[N],pw[N],res[N];
int p[N],mu[N],cnt;
bool vis[N];
void init()
{
	mu[1]=1; pw[0]=1; for(int i=1;i<N;i++) pw[i]=add(pw[i-1],pw[i-1]);
	for(int i=2;i<N;i++)
	{
		if(!vis[i]) p[++cnt]=i,mu[i]=-1;
		for(int j=1;j<=cnt;j++)
		{
			if(i*p[j]>=N) break;
			vis[i*p[j]]=1;
			if(i%p[j]==0) break;
			mu[i*p[j]]=-mu[i];
		}
	}
}
signed main()
{
	int n=read(); init();
	for(int i=1;i<=n;i++) a[read()]++;
	int ans=0;
	for(int i=2;i<N;i++)
	{
		if(!mu[i]) continue;
		int sum=0;
		for(int j=i;j<N;j+=i) sum+=a[j];
		// res[i]=mul(pw[sum]-1,n-sum);
		// printf("%d %d\n",i,mul(pw[sum]-1,n-sum));
		if(mu[i]==1) ans=sub(ans,mul(pw[sum]-1,n-sum));
		else if(mu[i]==-1) ans=add(ans,mul(pw[sum]-1,n-sum));
	}
	cout<<ans<<endl;
	return 0;
}