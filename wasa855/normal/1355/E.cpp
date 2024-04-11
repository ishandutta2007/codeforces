#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 100005
int a[N];
int n,A,R,M;
int solve(int m)
{
	int l=0,r=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]<m) l+=m-a[i];
		else r+=a[i]-m;
	}
	int K=min(l,r);
	int ans=K*M+(l-K)*A+(r-K)*R;
	return ans;
}
signed main()
{
	cin>>n>>A>>R>>M;
	for(int i=1;i<=n;i++) a[i]=read();
	M=min(M,A+R);
	if(A==0||R==0) {cout<<"0\n"; return 0;}
	int l=0,r=inf;
	while(r-l>=10)
	{
		int mid=(r-l)/3;
		if(solve(l+mid)>solve(r-mid)) l+=mid;
		else r-=mid;
	}
	int ans=INF;
	for(int i=l;i<=r;i++) ans=min(ans,solve(i));
	cout<<ans<<endl;
	return 0;
}