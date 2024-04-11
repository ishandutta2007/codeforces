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
#define N 1005
int a[N],n,vis[N];
int mex()
{
	memset(vis,0,sizeof(vis));
	for(int i=0;i<n;i++) vis[a[i]]=1;
	for(int i=0;i<=n;i++) if(!vis[i]) return i;
}
int ok()
{
	for(int i=0;i<n;i++) if(a[i]!=i) return i;
	return n;
}
void work()
{
	cin>>n; for(int i=0;i<n;i++) a[i]=read();
	vector<int> ans;
	while(ok()!=n)
	{
		int r=mex();
		if(r!=n)
		{
			ans.pb(r+1);
			a[r]=r;
		}
		else
		{
			int t=ok();
			a[t]=n;
			ans.pb(t+1);
		}
	}
	cout<<ans.size()<<endl;
	for(int i:ans) printf("%d ",i); cout<<"\n";
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}