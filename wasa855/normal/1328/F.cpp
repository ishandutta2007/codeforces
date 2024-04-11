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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
#define N 200005
int a[N],p[N],s[N],n,k;
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
	for(int i=n;i>=1;i--) s[i]=s[i+1]+a[i];
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==a[i-1]) cnt++;
		else
		{
			if(cnt>=k)
			{
				cout<<"0\n";
				return 0;
			}
			cnt=1;
		}
	}
	if(cnt>=k)
	{
		cout<<"0\n";
		return 0;
	}
	int ans=INF;
	for(int i=1;i<=n;i++)
	{
		if(i>=k)
		{
			int R=i*a[i]-p[i]-i+k;
			if(R<ans) ans=R;
		}
		if(i<=n-k+1)
		{
			int R=s[i]-(n-i+1)*a[i]-(n-i+1-k);
			if(R<ans) ans=R;
		}
		int R=i*a[i]-p[i]+s[i]-(n-i+1)*a[i]-n+k;
		if(R<ans) ans=R;
	}
	cout<<ans<<endl;
	return 0;
}