#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%lld%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 100005
char s[N];
int mx,n,d[5][5];
struct Trie
{
	int ch[N*20][4],cnt=1;
	void ins(int l,int r)
	{
		int cur=1;
		for(int i=l;i<=r;i++)
		{
			if(!ch[cur][s[i]-'A']) ch[cur][s[i]-'A']=++cnt;
			cur=ch[cur][s[i]-'A'];
		}
	}
	void dfs(int rt,int u,int dep)
	{
		for(int i=0;i<4;i++)
		{
			if(!ch[u][i]) d[rt][i]=min(d[rt][i],dep);
			else dfs(rt,ch[u][i],dep+1);
		}
	}
	void qry()
	{
		memset(d,0x3f,sizeof(d));
		for(int i=0;i<4;i++) dfs(i,ch[1][i],1);
	}
}tr;
int f[5][5],g[5][5],t[5][5];
void meg(int a[5][5],int b[5][5],int ans[5][5])
{
	memset(ans,0x3f,sizeof(t));
	for(int i=0;i<4;i++) for(int j=0;j<4;j++) for(int k=0;k<4;k++) ans[i][k]=min(ans[i][k],a[i][j]+b[j][k]);
}
int chk(int mid)
{
	memset(f,0,sizeof(f));
	memcpy(t,d,sizeof(t));
	while(mid)
	{
		if(mid&1) meg(f,t,g),memcpy(f,g,sizeof(f));
		meg(t,t,g),memcpy(t,g,sizeof(t));
		mid>>=1;
	}
	for(int i=0;i<4;i++) for(int j=0;j<4;j++)
	{
		if(f[i][j]<mx) return 1;
	}
	return 0;
}
signed main()
{
	cin>>mx; scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) tr.ins(i,min(i+9,n));
	tr.qry();
	// for(int i=0;i<4;i++) for(int j=0;j<4;j++) printf("%d%c",d[i][j]," \n"[j==3]);
	int l=1,r=mx,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(chk(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans+1<<endl;
	return 0;
}