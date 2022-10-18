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
	int n=read(),x=read(),sum=0;
	for(int i=1;i<=n;i++) a[i]=read()%x,sum=(sum+a[i])%x;
	if(sum!=0) {cout<<n<<endl; return ;}
	int l=1;
	while(a[l]==0&&l<=n) l++;
	if(l==n+1) {cout<<-1<<endl; return ;}
	int r=n;
	while(a[r]==0&&r>=1) r--;
	// cout<<"--\n";
	cout<<max(n-l,r-1)<<endl;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}