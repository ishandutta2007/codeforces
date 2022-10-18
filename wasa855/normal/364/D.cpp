#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
#define N 1000005
int a[N],n,b[N];
int solve()
{
	int id=rnd()%n+1;
	for(int i=1;i<=n;i++) b[i]=__gcd(a[i],a[id]);
	unordered_map<int,int> c;
	for(int i=1;i<=n;i++) c[b[i]]++;
	vector<int> d;
	int t=a[id];
	for(int i=1;i*i<=t;i++)
	{
		if(t%i==0)
		{
			d.pb(i);
			if(i*i!=t) d.pb(t/i);
		}
	}
	sort(d.begin(),d.end(),[&](int x,int y){return x>y;});
	for(int i:d)
	{
		int cnt=0;
		for(int j:d)
		{
			if(j%i==0) cnt+=c[j];
		}
		if(cnt*2>=n) return i;
	}
	return 1;
}
signed main()
{
	cin>>n; for(int i=1;i<=n;i++) a[i]=read();
	int ans=0;
	int T=10; while(T--) ans=max(ans,solve());
	cout<<ans<<endl;
	return 0;
}