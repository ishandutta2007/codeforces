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
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
int Inv(int x) {return qpow(x,mod-2);}
#define N 300005
int pre[N],suf[N],a[N],n,k,m;
int f[N],t[N],pos[N],cnt,bad[N],vis[N];
signed main()
{
	cin>>k>>n>>m;
	for(int i=1;i<=k;i++)
	{
		int l=read();
		for(int j=1;j<=l;j++) a[j]=read();
		for(int j=1;j<l;j++)
		{
			if(suf[a[j]]&&suf[a[j]]!=a[j+1]) bad[suf[a[j]]]=bad[a[j]]=1;
			suf[a[j]]=a[j+1];
		}
		for(int j=2;j<=l;j++)
		{
			if(pre[a[j]]&&pre[a[j]]!=a[j-1]) bad[pre[a[j]]]=bad[a[j]]=1;
			pre[a[j]]=a[j-1];
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(!pre[i])
		{
			int cnt=0,cur=i,bd=0;
			while(cur&&!vis[cur]) cnt++,vis[cur]=1,bd|=bad[cur],cur=suf[cur];
			if(!bd&&!cur) t[cnt]++;
		}
	}
	for(int i=1;i<=m;i++) if(t[i]) pos[++cnt]=i;
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=cnt;j++) if(i>=pos[j]) f[i]=add(f[i],mul(f[i-pos[j]],t[pos[j]]));
	}
	cout<<f[n]<<endl;
	return 0;
}