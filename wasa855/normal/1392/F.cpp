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
#define N 2000005
int a[N],b[N];
signed main()
{
	int n=read(),sum=0;
	for(int i=1;i<=n;i++) a[i]=read(),sum+=a[i];
	int x=(sum*2/n-n+1)/2;
	int y=sum-(2*x+n-1)*n/2;
	for(int i=1;i<=y;i++) b[i]=i+x;
	for(int i=y+1;i<=n;i++) b[i]=i+x-1;
	for(int i=1;i<=n;i++) printf("%lld ",b[i]); cout<<"\n";
	return 0;
}