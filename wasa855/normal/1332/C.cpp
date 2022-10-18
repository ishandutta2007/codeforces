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
#define N 200005
int fa[N],cnt[N][26],siz[N];
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
char s[N];
void work()
{
	int n=read(),k=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=0;
	for(int i=1;i<=n;i++) for(int j=0;j<26;j++) cnt[i][j]=0;
	for(int i=k+1;i<=n;i++) fa[find(i-k)]=find(i);
	for(int i=1;i*2<=n;i++) fa[find(i)]=find(n-i+1);
	int ans=n;
	vector<int> res;
	for(int i=1;i<=n;i++)
	{
		int u=find(i);
		if(u==i) res.pb(i);
		siz[u]++;
		cnt[u][s[i]-'a']++;
	}
	for(int i:res)
	{
		int maxn=0;
		for(int j=0;j<26;j++)
		{
			if(cnt[i][j]>maxn) maxn=cnt[i][j];
		}
		ans-=maxn;
	}
	printf("%d\n",ans);
}
signed main()
{
	int T=read();
	while(T--) work();
	return 0;
}