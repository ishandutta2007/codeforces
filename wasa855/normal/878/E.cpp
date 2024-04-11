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
#define mod 1000000007
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
#define N 100005
int fa[N];
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
int a[N],sum[N],len[N],pre[N],pw[N],ipw[N],n,Q;
int ans[N],pans[N];
void init()
{
	pw[0]=1; for(int i=1;i<N;i++) pw[i]=mul(pw[i-1],2);
	ipw[0]=1,ipw[1]=(mod+1)/2; for(int i=2;i<N;i++) ipw[i]=mul(ipw[i-1],ipw[1]);
	for(int i=1;i<=n;i++) pre[i]=add(pre[i-1],mul(add(a[i],mod),pw[i-1]));
	for(int i=1;i<=n;i++) fa[i]=i;
}
vector<pii> q[N];
int Query(int l,int r)
{
	return mul(sub(pre[r],pre[l-1]),ipw[l-1]);
}
signed main()
{
	cin>>n>>Q;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=Q;i++)
	{
		int l=read(),r=read();
		q[r].eb(l,i);
	}
	init();
	for(int i=1;i<=n;i++)
	{
		len[i]=1,sum[i]=a[i];
		while(find(i)>1&&sum[find(i)]>0)
		{
			int u=find(find(i)-1),v=find(i);
			if(len[u]>=30||(((ll)sum[v]<<len[u])+sum[u]>=inf)) sum[u]=inf;
			else sum[u]=((ll)sum[v]<<len[u])+sum[u];
			len[u]+=len[v];
			fa[v]=u;
		}
		pans[find(i)]=add(pans[find(find(i)-1)],mul(2,Query(find(i),i)));
		// cout<<pans[find(i)]<<endl;
		// for(int j=1;j<=i;j++) printf("%d %d\n",j,find(j));
		for(auto [l,id]:q[i])
		{
			ans[id]=sub(pans[find(i)],pans[find(l)]);
			// cout<<ans[id]<<endl;
			ans[id]=add(ans[id],Query(l,find(l)+len[find(l)]-1));
		}
	}
	for(int i=1;i<=Q;i++) printf("%d\n",ans[i]);
	return 0;
}