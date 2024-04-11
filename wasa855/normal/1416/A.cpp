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
#define N 300005
int a[N],ans[N];
vector<int> v[N];
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) v[i].pb(0);
	for(int i=1;i<=n;i++) a[i]=read(),v[a[i]].pb(i);
	for(int i=1;i<=n;i++) v[i].pb(n+1);
	for(int i=1;i<=n;i++) ans[i]=inf;
	for(int i=1;i<=n;i++)
	{
		int Max=0;
		for(int j=0;j+1<(int)v[i].size();j++) Max=max(Max,v[i][j+1]-v[i][j]);
		if(Max<=n) ans[Max]=min(ans[Max],i);
	}
	for(int i=2;i<=n;i++) ans[i]=min(ans[i],ans[i-1]);
	for(int i=1;i<=n;i++) printf("%d%c",ans[i]==inf?-1:ans[i]," \n"[i==n]);
	for(int i=1;i<=n;i++) v[i].clear();
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}