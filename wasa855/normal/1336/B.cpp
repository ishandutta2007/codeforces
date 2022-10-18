#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 100005
int ans;
void solve(vector<int> a,vector<int> b,vector<int> c)
{
	int j=0,k=0;
	for(int i=0;i<(int)a.size();i++)
	{
		while(j<(int)b.size()&&a[i]>b[j]) j++;
		if(j==(int)b.size()) return ;
		while(k<(int)c.size()&&b[j]>=c[k]) k++;
		if(k==0) continue;
		int R=(a[i]-b[j])*(a[i]-b[j])+(a[i]-c[k-1])*(a[i]-c[k-1])+(b[j]-c[k-1])*(b[j]-c[k-1]);
		if(R<ans) ans=R;
	}
}
void work()
{
	int n,m,k; ans=INF;
	cin>>n>>m>>k;
	vector<int> a(n),b(m),c(k);
	for(int i=0;i<n;i++) a[i]=read();
	for(int i=0;i<m;i++) b[i]=read();
	for(int i=0;i<k;i++) c[i]=read();
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	sort(c.begin(),c.end());
	solve(a,b,c); solve(a,c,b);
	solve(b,a,c); solve(b,c,a);
	solve(c,a,b); solve(c,b,a);
	cout<<ans<<endl;
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}