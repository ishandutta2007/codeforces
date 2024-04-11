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
#define N 45
int f[N][N],st[N],siz[N],q[N],n,k,ful;
int popcnt(int x) {return __builtin_popcountll(x);}
int lowbit(int x) {return x&(-x);}
void dfs(int dep,int cur)
{
	// printf("%lld %lld\n",dep,cur);
	if(dep==k+1)
	{
		if(cur!=ful&&lowbit(cur^ful)!=cur+1)
		{
			cout<<"REJECTED\n";
			exit(0);
		}
		return ;
	}
	int go=popcnt(cur&f[dep][q[dep]]);
	cur&=(~f[dep][q[dep]]);
	// printf("%d %d\n",dep,go);
	for(int j=go;j<=go+popcnt(siz[dep]);j++)
	{
		dfs(dep+1,cur|f[dep][j]);
	}
}
signed main()
{
	cin>>n>>k; ful=(1LL<<n)-1;
	if(n==1)
	{
		cout<<"ACCEPTED\n";
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		q[i]=read(); int tmp=0;
		for(int j=1;j<=q[i];j++) f[i][j]=f[i][j-1]|(1LL<<(read()-1));
		tmp=f[i][q[i]];
		siz[i]=(st[i-1]^ful)&tmp;
		st[i]=st[i-1]|tmp;
	}
	// for(int i=1;i<=k;i++) printf("%lld\n",siz[i]);
	dfs(1,0);
	// for(int i=1;i<=k;i++) printf("%d\n",st[i]);
	if(popcnt(st[k])!=n)
	{
		cout<<"REJECTED\n";
		return 0;
	}
	cout<<"ACCEPTED\n";
	return 0;
}