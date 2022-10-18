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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
#define N 100005
bool a[N],b[N];
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) a[i]=b[i]=0;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int m=read(); vector<int> v;
		for(int j=1;j<=m;j++) v.pb(read());;
		sort(v.begin(),v.end());
		for(int j:v)
		{
			if(!b[j])
			{
				a[i]=b[j]=1; cnt++;
				break;
			}
		}
	}
	if(cnt==n) cout<<"OPTIMAL\n";
	else
	{
		cout<<"IMPROVE\n";
		for(int i=1;i<=n;i++)
		{
			if(!a[i])
			{
				printf("%d ",i); break;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!b[i])
			{
				printf("%d\n",i); break;
			}
		}
	}
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}