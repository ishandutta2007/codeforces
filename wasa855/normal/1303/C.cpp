#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
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
#define N 30
string s;
bool c[N][N];
vector<int> G[N];
bool vis[N];
int d[N];
string ans;
void work()
{
	cin>>s;
	ans="";
	int n=s.length();
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	memset(vis,0,sizeof(vis));
	for(int i=0;i<26;i++) G[i].clear();
	for(int i=0;i<n-1;i++)
	{
		c[s[i]-'a'][s[i+1]-'a']=1;
		c[s[i+1]-'a'][s[i]-'a']=1;
	}
	bool ok=1;
	int cnt=0;
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++) d[i]+=c[i][j];
		if(d[i]>2) ok=0;
	}
	if(!ok)
	{
		cout<<"NO\n";
		return ;
	}
	for(int i=0;i<26;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(c[i][j])
			{
//				printf("%d %d\n",i,j);
				G[i].pb(j);
			}
		}
	}
	vector<int> be;
	for(int i=0;i<26;i++)
	{
		if(G[i].size()==1) be.pb(i);
	}
	for(int i=0;i<(int)be.size();i++)
	{
		int las=be[i],cur=G[las][0];
		if(vis[las]) continue;
		ans+=(las+'a');
		vis[las]=1;
		while(1)
		{
			vis[cur]=1;
			ans+=(cur+'a');
			if(G[cur].size()==1) break;
			if(G[cur][0]==las) swap(G[cur][0],G[cur][1]);
			int t=cur;las=cur,cur=G[t][0];
		}
	}
	for(int i=0;i<26;i++)
	{
		if(!vis[i])
		{
			if(G[i].size()!=0)
			{
				cout<<"NO\n";
				return ;
			}
			ans+=(i+'a');
		}
	}
	cout<<"YES\n";
	cout<<ans<<"\n";
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}