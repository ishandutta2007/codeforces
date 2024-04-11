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
#define N 300005
int a[N],n,ans;
void work()
{
	int n=read(),q=read(); for(int i=1;i<=n;i++) a[i]=read();
	ans=0; for(int i=1;i<=n;i++) ans+=max(a[i]-a[i-1],0LL);
	cout<<ans<<endl;
	while(q--)
	{
		int x=read(),y=read();
		if(x==y)
		{
			printf("%lld\n",ans);
			continue;
		}
		ans-=max(a[x]-a[x-1],0LL);
		if(x!=n) ans-=max(a[x+1]-a[x],0LL);
		if(x!=y-1) ans-=max(a[y]-a[y-1],0LL);
		if(y!=n) ans-=max(a[y+1]-a[y],0LL);
		// cout<<ans<<endl;
		swap(a[x],a[y]);
		ans+=max(a[x]-a[x-1],0LL);
		if(x!=n) ans+=max(a[x+1]-a[x],0LL);
		if(x!=y-1) ans+=max(a[y]-a[y-1],0LL);
		if(y!=n) ans+=max(a[y+1]-a[y],0LL);
		printf("%lld\n",ans);
	}
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}