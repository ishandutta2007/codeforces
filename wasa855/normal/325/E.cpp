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
#define N 100005
bool vis[N];
int n;
vector<int> ans;
void dfs(int u)
{
	vis[u]=1;
	int v=(u*2)%n;
	if(!vis[v]) dfs(v);
	v=(u*2+1)%n;
	if(!vis[v]) dfs(v);
	ans.pb(u);
}
signed main()
{
	n=read();
	if(n==1)
	{
		cout<<"0\n";
		return 0;
	}
	if(n&1)
	{
		cout<<"-1\n";
		return 0;
	}
	ans.pb(0);
	dfs(0);
	reverse(ans.begin(),ans.end());
	for(int i:ans) printf("%d ",i);
	return 0;
}