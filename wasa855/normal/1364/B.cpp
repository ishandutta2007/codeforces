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
#define N 100005
int a[N];
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	vector<int> ans; ans.pb(a[1]);
	for(int i=1;i<n;)
	{
		int r=i+1;
		while(r<n&&1LL*(a[r+1]-a[r])*(a[r]-a[r-1])>=0) r++;
		ans.pb(a[r]); i=r;
	}
	cout<<ans.size()<<endl;
	for(int i:ans) printf("%d ",i); cout<<"\n";
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}