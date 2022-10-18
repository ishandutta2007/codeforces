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
vector<int> v[N];
int a[N];
signed main()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		int t=a[i];
		for(int j=2;j*j<=t;j++)
		{
			if(t%j==0)
			{
				int cnt=0;
				while(t%j==0) t/=j,cnt++;
				v[j].pb(cnt);
			}
		}
		if(t!=1) v[t].pb(1);
	}
	int ans=1;
	for(int i=1;i<N;i++)
	{
		if((int)v[i].size()>=n-1)
		{
			sort(v[i].begin(),v[i].end(),[&](int x,int y){return x>y;});
			int minn=inf;
			for(int j=0;j<n-1;j++) if(v[i][j]<minn) minn=v[i][j];
			while(minn--) ans*=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}