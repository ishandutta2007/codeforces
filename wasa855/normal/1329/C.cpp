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
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N (1<<22)
#define ls (u<<1)
#define rs (u<<1|1)
int a[N],lg[N];
int getdep(int u)
{
	if(a[ls]==0&&a[rs]==0) return lg[u];
	if(a[ls]>a[rs]) return getdep(ls);
	return getdep(rs);
}
void del(int u)
{
	if(a[ls]==0&&a[rs]==0) {a[u]=0; return ;}
	if(a[ls]>a[rs]) {a[u]=a[ls]; del(ls);}
	else {a[u]=a[rs]; del(rs);}
}
void work()
{
	int n=read(),m=read();
	memset(a,0,sizeof(int)*(1<<(n+1)));
	for(int i=1;i<(1<<n);i++) a[i]=read();
	vector<int> ans;
	for(int i=1;i<(1<<m);i++)
	{
		while(getdep(i)>m) del(i),ans.pb(i);
	}
	ll sum=0;
	for(int i=1;i<(1<<m);i++) sum+=a[i];
	printf("%lld\n",sum);
	for(int i:ans) printf("%d ",i); puts("");
}
signed main()
{
	for(int i=1;i<N;i++) lg[i]=lg[i>>1]+1;
	int T=read();
	while(T--) work();
	return 0;
}