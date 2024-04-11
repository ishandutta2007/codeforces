#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define int long long
#define mod 998244353
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 200005
inline int lowbit(int x){return x&(-x);}
inline int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
int inv(int x)
{
	return qpow(x,mod-2);
}
int a[N],n;
int c[N],s[N];
struct BIT
{
	int t[N];
	void add(int u,int d)
	{
		for(int i=u;i<=n;i+=lowbit(i)) t[i]+=d;
	}
	int query(int u)
	{
		int ans=0;
		for(int i=u;i>0;i-=lowbit(i)) ans+=t[i];
		return ans;
	}
};
BIT t;
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
//	cout<<5*inv(2)%mod<<endl;;
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	int m=0;
	int ans=0;
	for(int i=1;i<=n;i++) c[i]=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==-1) s[i]=s[i-1]+1;
		else s[i]=s[i-1];
	}
	for(int i=n;i>=1;i--)
	{
		if(a[i]==-1) m++;
		else
		{
			ans+=t.query(a[i]);
			t.add(a[i],1);
			c[a[i]]=0;
		}
	}
	for(int i=1;i<=n;i++) c[i]+=c[i-1];
//	for(int i=1;i<=n;i++) printf("%lld ",c[i]); cout<<"\n";
//	cout<<m<<endl;
	ans+=m*(m-1)%mod*inv(4)%mod;
//	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==-1) continue;
		int y=c[a[i]],x=m-y;
		int a=s[i],b=m-a;
//		printf("%lld %lld %lld %lld %lld\n",i,x,y,a,b);
		ans=(ans+(a*x+b*y)%mod*inv(m))%mod;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}