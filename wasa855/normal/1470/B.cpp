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
int a[N],n,Q;
vector<int> prd[N];
map<vector<int>,int> ans;
void work()
{
	cin>>n; ans.clear();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) prd[i].clear();
	for(int i=1;i<=n;i++)
	{
		int t=a[i];
		for(int j=2;j*j<=t;j++)
		{
			if(t%j==0)
			{
				int c=0;
				while(t%j==0) t/=j,c++;
				if(c&1) prd[i].pb(j);
			}
		}
		if(t!=1) prd[i].pb(t);
	}
	int a1=0,a2=0;
	sort(prd+1,prd+n+1);
	vector<int> ept;
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(j<n&&prd[j+1]==prd[j]) j++;
		a1=max(a1,j-i+1);
		if((j-i+1)&1) ans[prd[j]]+=j-i+1;
		else ans[ept]+=j-i+1;
		i=j;
	}
	for(auto [x,y]:ans)
	{
		a2=max(a2,y);
		// printf("%d:",y); print(x);
	}
	int Q=read();
	while(Q--)
	{
		ll x; scanf("%lld",&x);
		if(x==0) printf("%d\n",a1);
		else printf("%d\n",a2);
	}
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}