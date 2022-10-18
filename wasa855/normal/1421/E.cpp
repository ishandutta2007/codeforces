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
#define N 200005
int a[N],b[N],sum[N];
signed main()
{
	int n=read();
	if(n==1)
	{
		cout<<read()<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) a[i]=b[i]=read();
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+b[i];
	int l;
	if(n%3==0) l=n-2;
	else if(n%3==1) l=n-1;
	else l=n;
	int ans=-INF;
	while(l>=0)
	{
		int tmp=(sum[n]-sum[l])-(sum[l]);
		if(l*2+1==n)
		{
			int res=0;
			for(int i=1;i<=n;i++)
			{
				if(i&1) res+=a[i];
				else res-=a[i];
			}
			if(res==tmp) tmp-=(b[n/2+1]-b[n/2])*2;
		}
		ans=max(ans,tmp);
		l-=3;
	}
	cout<<ans<<endl;
	return 0;
}