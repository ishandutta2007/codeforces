#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 1005
int a[N],n;
stack<pii> ans;
bool ok()
{
	for(int i=1;i<=n;i++)
	{
		if(i!=a[i]) return 0;
	}
	return 1;
}
void dfs(int dep)
{
	if(ok())
	{
		cout<<ans.size()<<endl;
		while(!ans.empty())
		{
			printf("%d %d\n",ans.top().fir,ans.top().sec);
			ans.pop();
		}
		exit(0);
	}
	if(dep==0) return ;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i&&(abs(a[i]-a[i-1])!=1||abs(a[i]-a[i+1])!=1))
		{
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]!=j&&(abs(a[j]-a[j-1])!=1||abs(a[j]-a[j+1])!=1))
				{
					ans.push(mp(i,j));
					reverse(a+i,a+j+1);
					dfs(dep-1);
					ans.pop();
					reverse(a+i,a+j+1);
				}
			}
		}
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	a[0]=-1,a[n+1]=-1;
	dfs(3);
	return 0;
}