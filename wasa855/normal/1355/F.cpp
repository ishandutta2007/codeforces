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
int p[N],vis[N],cnt,tot;
int Query(int x)
{
	if(tot==22) assert(0);
	cout<<"? "<<x<<endl; tot++;
	return read();
}
void out(int x)
{
	cout<<"! "<<x<<endl;
}
void init(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) p[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			if(i*p[j]>n) break;
			vis[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
void work()
{
	int cur=1,res=1; tot=0;
	vector<int> h,g;
	for(int i=1;i<=cnt;i++)
	{
		if((long double)res*p[i]>1e18)
		{
			int r=Query(res);
			for(int i=2;i*i<=r;i++)
			{
				if(r%i==0) h.pb(i),r/=i;
			}
			if(r!=1) h.pb(r);
			res=1;
		}
		res*=p[i];
	}
	int r=Query(res);
	for(int i=2;i*i<=r;i++)
	{
		if(r%i==0) h.pb(i),r/=i;
	}
	if(r!=1) h.pb(r);
	if(h.empty())
	{
		out(8);
		return ;
	}
	int ans=1;
	for(int i=0;i<(int)h.size()-1;i+=2)
	{
		int a=h[i],b=h[i+1];
		int qaq=a,r=1;
		while(qaq*a<=1000000000) qaq*=a;
		r=qaq;qaq=1;
		while(qaq*b<=1000000000) qaq*=b;
		r=Query(r*qaq); ans*=r;
	}
	if((int)h.size()&1)
	{
		int a=h.back();
		int qaq=a;
		while(qaq*a<=1000000000) qaq*=a;
		ans*=Query(qaq);
	}
	int O=1;
	for(int i=2;i*i<=ans;i++)
	{
		if(ans%i==0)
		{
			int cnt=0;
			while(ans%i==0) ans/=i,cnt++;
			O*=(cnt+1);
		}
	}
	if(ans!=1) O*=2;
	out(max(O*2,8LL));
}
signed main()
{
	init(682);
	// cout<<cnt<<endl;
	// int res=1,ans=0;
	// for(int i=1;i<=cnt;i++)
	// {
		// if((long double)res*p[i]>1e18) res=1,ans++;
		// res*=p[i];
		// printf("%lld %lld\n",i,res);
	// }
	// cout<<res<<endl;
	// cout<<ans+1<<endl;
	// return 0;
	int T=read();
	while(T--) work();
	return 0;
}