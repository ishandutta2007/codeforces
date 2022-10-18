#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define INF 0x3fffffff
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
#define N 500005
int n,k,m,ans;
int l[N],r[N],x[N],f[N],lim[N],a[N];
int solve(int u)
{
	memset(f,0,sizeof(f));
	memset(a,0,sizeof(a));
	memset(lim,0,sizeof(lim));
	for(int i=1;i<=m;i++)
	{
		if(x[i]&(1<<u)) a[l[i]]++,a[r[i]+1]--;
		else lim[r[i]]=max(lim[r[i]],l[i]);
	}
	for(int i=1;i<=n+1;i++) a[i]+=a[i-1];
	f[0]=1;
	int l=0,sum=1;
	for(int i=1;i<=n+1;i++)
	{
		while(l<lim[i-1]) sum=sub(sum,f[l++]);
		if(a[i]) continue;
		f[i]=sum;
		sum=add(sum,f[i]);
	}
	return f[n+1];
}
signed main()
{
	cin>>n>>k>>m;
	for(int i=1;i<=m;i++) l[i]=read(),r[i]=read(),x[i]=read();
	ans=1;
	for(int i=0;i<k;i++) ans=mul(ans,solve(i));
	cout<<ans<<endl;
	return 0;
}