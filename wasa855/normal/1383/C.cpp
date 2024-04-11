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
#define N 25
const int M=(1<<20);
char s[100005],t[100005];
int g[M],f[M];
int fa[N];
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
int a[N];
void work()
{
	int n=read();
	scanf("%s%s",s+1,t+1);
	memset(g,0,sizeof(g)); memset(f,0,sizeof(f)); memset(a,0,sizeof(a));
	for(int i=0;i<20;i++) fa[i]=i;
	for(int i=1;i<=n;i++) if(s[i]!=t[i]) g[(s[i]-'a')]|=1<<(t[i]-'a'),fa[find(s[i]-'a')]=find(t[i]-'a');
	for(int i=0;i<20;i++) f[1<<i]=1;
	for(int i=0;i<M;i++)
	{
		if(!f[i]) continue;
		for(int j=0;j<20;j++)
		{
			if(!(i&(1<<j))) if(!(g[j]&i))
			{
				// if((i|(1<<j))==7) printf("%d %d\n",i,j);
				f[i|(1<<j)]=1;
			}
		}
	}
	for(int i=0;i<20;i++) a[find(i)]|=1<<i;
	int ans=40;
	for(int i=0;i<20;i++)
	{
		if(find(i)!=i) continue;
		int maxn=0;
		for(int j=a[i];j!=0;j=(j-1)&a[i]) if(f[j]) maxn=max(maxn,__builtin_popcount(j));
		ans-=maxn+1;
	}
	cout<<ans<<endl;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}