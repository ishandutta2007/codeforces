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
#define N 1000005
int a[N],b[N],c[N],d[N],e[N];
signed main()
{
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;++i) a[i]=read(),b[i]=read();
	for(int i=1;i<=m;++i) c[i]=read(),d[i]=read();
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			int x=c[j]-a[i];
			if(x>=0) e[x]=max(e[x],d[j]-b[i]+1);
		}
	}
	int ans=inf;
	for(int i=1000000;i>=0;--i) e[i]=max(e[i],e[i+1]),ans=min(ans,e[i]+i);
	cout<<ans<<endl;
	return 0;
}