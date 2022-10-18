#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
#define N 50005
int pw[15],cnt[1<<24];
int a[N];
int w,n,Q;
char s[15];
int get(int x)
{
	int res=0;
	for(int i=0;i<w;i++) if(x&(1<<i)) res+=pw[i];
	return res;
}
int dfs(int dep,int cur)
{
	if(dep==w) return cnt[cur];
	if(s[dep]=='A') return dfs(dep+1,cur)+dfs(dep+1,cur+pw[dep]);
	if(s[dep]=='O') return dfs(dep+1,cur);
	if(s[dep]=='X') return dfs(dep+1,cur)+dfs(dep+1,cur+pw[dep]*2);
	if(s[dep]=='a') return dfs(dep+1,cur+pw[dep]*2);
	if(s[dep]=='o') return dfs(dep+1,cur+pw[dep])+dfs(dep+1,cur+pw[dep]*2);
	if(s[dep]=='x') return dfs(dep+1,cur+pw[dep]);
}
signed main()
{
	cin>>w>>n>>Q;
	pw[0]=1; for(int i=1;i<=w;i++) pw[i]=pw[i-1]*3;
	for(int i=1;i<=n;i++) a[read()]++;
	for(int i=0;i<(1<<w);i++)
	{
		for(int j=0;j<(1<<w);j++)
		{
			cnt[get(i)+get(j)]+=a[i]*a[j];
		}
	}
	while(Q--)
	{
		scanf("%s",s);
		reverse(s,s+w);
		printf("%lld\n",dfs(0,0));
	}
	return 0;
}