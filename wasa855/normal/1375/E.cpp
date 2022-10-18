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
int a[N];
vector<pii> ans;
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		vector<pii> b;
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]>a[j]) b.eb(a[j],j);
		}
		sort(b.begin(),b.end(),[&](pii x,pii y)
		{
			if(x.fir!=y.fir) return x.fir>y.fir;
			return x.sec>y.sec;
		});
		for(auto j:b) ans.eb(i,j.sec);
	}
	cout<<ans.size()<<endl;
	for(auto [x,y]:ans) printf("%d %d\n",x,y);
	return 0;
}