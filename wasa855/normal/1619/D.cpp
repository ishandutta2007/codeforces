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
int cnt[N],a[N],n,m;
int getid(int x,int y) {return (x-1)*n+y;}
int chk(int mid)
{
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) cnt[getid(i,j)]=a[getid(i,j)]>=mid;
	int ok=1,fl=0;
	for(int j=1;j<=n;j++)
	{
		int tmp=0; for(int i=1;i<=m;i++) tmp|=cnt[getid(i,j)];
		ok&=tmp;
	}
	for(int i=1;i<=m;i++)
	{
		int tmp=0; for(int j=1;j<=n;j++) tmp+=cnt[getid(i,j)];
		fl|=tmp>=2;
	}
	return ok&&fl;
}
void work()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) a[getid(i,j)]=read();
	int l=0,r=inf,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(chk(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}