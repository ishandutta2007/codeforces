#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 200005
int a[N],b[N],cnt[N];
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=b[i]=read();
	sort(a+1,a+n+1); int Q=unique(a+1,a+n+1)-a-1;
	for(int i=1;i<=n;i++) b[i]=lower_bound(a+1,a+Q+1,b[i])-a;
	memset(cnt,0,sizeof(int)*(Q+2));
	int ans=1,cur=0;
	// for(int i=1;i<=n;i++) printf("%d ",b[i]); cout<<"\n";
	for(int i=1;i<=n;i++) cnt[b[i]]++;
	while(cur<=Q)
	{
		int tsum=0,ok=0;
		for(int i=cur+1;i<=Q;i++)
		{
			tsum+=cnt[i];
			// printf("%d %d %d\n",ans,tsum,i);
			if(ans+tsum-1>=a[i]) {ok=i; break;}
		}
		if(ok) cur=ok,ans+=tsum;
		else break;
	}
	cout<<ans<<endl;
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}