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
#define N 200005
int fa[N];
int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
struct Node{int x,y,t,id;};
Node a[N];
int n,mn[N],k;
int chk(int mid)
{
	int cnt=0;
	for(int i=1;i<=n;i++) if(mn[i]!=inf)
	{
		if(mn[i]>mid) cnt++;
	}
	return cnt<=mid+1;
}
void work()
{
	n=read(),k=read();
	for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),a[i].t=read(),a[i].id=i;
	for(int i=1;i<=n;i++) fa[i]=i;
	sort(a+1,a+n+1,[&](Node x,Node y){return x.x<y.x||(x.x==y.x&&x.y<y.y);});
	for(int i=1;i<n;i++)
	{
		if(a[i].x==a[i+1].x&&a[i+1].y-a[i].y<=k) fa[find(a[i].id)]=find(a[i+1].id);
	}
	sort(a+1,a+n+1,[&](Node x,Node y){return x.y<y.y||(x.y==y.y&&x.x<y.x);});
	for(int i=1;i<n;i++)
	{
		if(a[i].y==a[i+1].y&&a[i+1].x-a[i].x<=k) fa[find(a[i].id)]=find(a[i+1].id);
	}
	for(int i=1;i<=n;i++) mn[i]=inf;
	for(int i=1;i<=n;i++) mn[find(a[i].id)]=min(mn[find(a[i].id)],a[i].t);
	// for(int i=1;i<=n;i++) printf("%d%c",mn[i]," \n"[i==n]);
	int l=0,r=inf,ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(chk(mid)) ans=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",ans);
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}