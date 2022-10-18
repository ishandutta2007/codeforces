#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 200005
int lowbit(int u){return u&(-u);}
int a[N],b[N],B=2e9;
int c[N],t[N],n;
void add(int u,int d)
{
	while(u<=n)
	{
		t[u]+=d;
		u+=lowbit(u);
	}
}
int query(int u)
{
	if(u==0) return 0;
	int ans=0;
	while(u)
	{
		ans+=t[u];
		u-=lowbit(u);
	}
	return ans;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	for(int i=1;i<=n;i++) c[i]=b[i]-a[i];
	sort(c+1,c+n+1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=n,R;
		if(c[1]>=a[i]-b[i]) R=0;
		else if(c[n]<a[i]-b[i]) R=n;
		else
		{
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(a[i]-b[i]>c[mid]) l=mid+1,R=mid;
				else r=mid-1;
			}
		}
		// cout<<R<<" ";
		// cout<<query(R)<<endl;
		ans+=query(R);
		R=lower_bound(c+1,c+n+1,b[i]-a[i])-c;
		add(R,1);
	}
	cout<<ans<<endl;
	return 0;
}

//