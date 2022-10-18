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
#define N 2505
int a[N],rev[N],n;
vector<int> ans;
void doit(int p)
{
	assert(p&1);
	ans.pb(p);
	reverse(a+1,a+p+1);
	for(int i=1;i<=n;i++) rev[a[i]]=i;
}
void work()
{
	cin>>n; for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) if((a[i]-i)&1) {cout<<"-1\n"; return ;}
	for(int i=1;i<=n;i++) rev[a[i]]=i;
	ans.clear();
	for(int i=n;i>=5;i-=2)
	{
		int p1=rev[i],p2=rev[i-1];
		if(p1>p2) doit(p1);
		else doit(p1);
		p1=rev[i],p2=rev[i-1];
		doit(p2-1);
		p1=rev[i],p2=rev[i-1];
		doit(p2+1);
		p1=rev[i],p2=rev[i-1];
		doit(p1);
		p1=rev[i],p2=rev[i-1];
		doit(i);
	}
	if(a[1]==3) doit(3);
	// for(int i=1;i<=n;i++) printf("%d%c",a[i]," \n"[i==n]);
	cout<<ans.size()<<endl;
	print(ans);
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}