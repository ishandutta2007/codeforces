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
int a[N],c[N],t[N];
vector<int> res[N];
signed main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=k;i++) c[i]=read();
	sort(a+1,a+n+1);
	int ans=0,cur=n,now=1;
	for(int i=k;i>=1;i--)
	{
		if(c[i]!=c[i+1]) now=1;
		while(cur>=1&&a[cur]==i)
		{
			while(t[now]==c[i]) now++;
			res[now].pb(a[cur]); cur--;
			t[now]++;
			if(now>ans) ans=now;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++)
	{
		printf("%d ",(int)res[i].size());
		for(int j:res[i]) printf("%d ",j);
		printf("\n");
	}
	return 0;
}