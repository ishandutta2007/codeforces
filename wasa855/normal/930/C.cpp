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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 100005
int s[N],n,m;
struct BIT
{
	int lowbit(int x) {return x&(-x);}
	int v[N];
	void init() {memset(v,0,sizeof(v));}
	void upd(int p,int q)
	{
		p++;
		for(int i=p;i<N;i+=lowbit(i)) v[i]=max(v[i],q);
	}
	int qry(int p)
	{
		int ans=0;
		p++;
		for(int i=p;i>=1;i-=lowbit(i)) ans=max(ans,v[i]);
		return ans;
	}
}bit;
int f[N],g[N];
signed main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		int l=read(),r=read();
		s[l]++,s[r+1]--;
	}
	for(int i=1;i<=n;i++) s[i]+=s[i-1];
	for(int i=1;i<=n;i++)
	{
		f[i]=bit.qry(s[i])+1;
		bit.upd(s[i],f[i]);
	}
	bit.init();
	for(int i=n;i>=1;i--)
	{
		g[i]=bit.qry(s[i])+1;
		bit.upd(s[i],g[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans=max(ans,f[i]+g[i+1]);
	cout<<ans<<endl;
	return 0;
}