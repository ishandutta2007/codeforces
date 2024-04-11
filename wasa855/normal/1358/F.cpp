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
#define N 200005
vector<int> a,b;
vector<char> ans;
int n;
void solve1()
{
	if(a[0]==b[0]) cout<<"SMALL\n0\n";
	else cout<<"IMPOSSIBLE\n";
}
bool rsame(vector<int> x,vector<int> y)
{
	reverse(x.begin(),x.end());
	return x==y;
}
void fail() {cout<<"IMPOSSIBLE\n",exit(0);}
bool push_back(char s)
{
	if((int)ans.size()<=200000) {ans.pb(s); return 1;}
	return 0;
}
void solve2()
{
	int tot=0,sum=0;
	while(a!=b&&!rsame(a,b))
	{
		if(b[0]>b[1]) swap(b[0],b[1]),tot++,pb('R');
		if(a[0]>a[1]&&b[0]==a[1])
		{
			if(b[0]==0) fail();
			if(b[1]<a[0]) fail();
			int ned=b[1]-a[0];
			if(ned%b[0]!=0) fail();
			sum+=ned/b[0],tot+=ned/b[0]+1;
			if(sum<=200000)
			{
				for(int i=1;i<=ned/b[0];i++) pb('P');
				pb('R');
			}
			if(sum<=200000)
			{
				cout<<"SMALL\n";
				reverse(ans.begin(),ans.end());
				cout<<(int)ans.size()<<endl;
				for(auto i:ans) putchar(i);
			}
			else
			{
				cout<<"BIG\n";
				cout<<sum<<endl;
			}
			exit(0);
		}
		if(b[0]==a[0])
		{
			if(b[0]==0) fail();
			if(b[1]<a[1]) fail();
			int ned=b[1]-a[1];
			if(ned%b[0]!=0) fail();
			sum+=ned/b[0],tot+=ned/b[0]+1;
			if(sum<=200000)
			{
				for(int i=1;i<=ned/b[0];i++) pb('P');
				pb('R');
			}
			if(sum<=200000)
			{
				cout<<"SMALL\n";
				reverse(ans.begin(),ans.end());
				cout<<(int)ans.size()<<endl;
				for(auto i:ans) putchar(i);
			}
			else
			{
				cout<<"BIG\n";
				cout<<sum<<endl;
			}
			exit(0);
		}
		if(b[0]==0) fail();
		tot+=b[1]/b[0];
		sum+=b[1]/b[0];
		if(sum<=200000)
		{
			for(int i=1;i<=b[1]/b[0];i++) pb('P');
		}
		b[1]%=b[0];
	}
	if(a!=b) swap(b[0],b[1]),tot++,pb('R');
	if(sum<=200000)
	{
		cout<<"SMALL\n";
		reverse(ans.begin(),ans.end());
		cout<<(int)ans.size()<<endl;
		for(auto i:ans) putchar(i);
	}
	else
	{
		cout<<"BIG\n";
		cout<<sum<<endl;
	}
	exit(0);
}
bool inc(vector<int> x)
{
	for(int i=1;i<n;i++)
	{
		if(x[i]<x[i-1]) return 0;
	}
	return 1;
}
bool dec(vector<int> x)
{
	for(int i=1;i<n;i++)
	{
		if(x[i]>x[i-1]) return 0;
	}
	return 1;
}
bool alz(vector<int> x)
{
	for(int i=0;i<n-1;i++) if(x[i]!=0) return 0;
	return 1;
}
void print(vector<int> x)
{
	for(int i:x) printf("%lld ",i); cout<<"\n";
}
void solve3()
{
	int tot=0,sum=0;
	while(a!=b&&!rsame(a,b))
	{
		if(alz(b)) fail();
		if(dec(b)) reverse(b.begin(),b.end()),tot++,pb('R');
		if(!inc(b)) fail();
		// if(tot%10000==0) print(b);
		sum++; tot++; pb('P');
		for(int i=n-1;i>0;i--) b[i]-=b[i-1];
	}
	if(a!=b) reverse(b.begin(),b.end()),tot++,pb('R');
	if(sum<=200000)
	{
		cout<<"SMALL\n";
		cout<<ans.size()<<endl;
		reverse(ans.begin(),ans.end());
		for(auto i:ans) putchar(i);
	}
	else
	{
		cout<<"BIG\n";
		cout<<sum<<endl;
	}
}
signed main()
{
	cin>>n;
	a.resize(n),b.resize(n);
	for(int i=0;i<n;i++) a[i]=read();
	for(int i=0;i<n;i++) b[i]=read();
	if(n>=3) solve3();
	else if(n==2) solve2();
	else solve1();
	return 0;
}