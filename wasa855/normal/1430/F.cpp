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
#define N 2005
int n,k,a[N];
int l[N],r[N],v[N];
vector<pii> f,g;
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) l[i]=read(),r[i]=read(),v[i]=read();
	f.eb(k,0);
	for(int i=1;i<=n;i++)
	{
		if(l[i]>r[i-1])
		{
			int minn=INF;
			for(auto [x,y]:f)
			{
				minn=min(minn,(x==k?0:x)+y);
				if(x!=k) g.eb(x,y);
			}
			if(minn<INF) g.eb(k,minn);
			f=g; g.clear();
		}
		for(auto [x,y]:f)
		{
			int A=y+v[i];
			int ned=(max(0LL,v[i]-x)+k-1)/k;
			if(l[i]+ned>r[i]) continue;
			int B=ned*k-v[i]+x;
			g.eb(B,A);
			if(l[i]+ned!=r[i]) g.eb(k,A+B);
		}
		f=g; g.clear();
	}
	int ans=INF;
	for(auto [x,y]:f) ans=min(ans,y);
	if(ans==INF) cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}