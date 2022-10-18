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
#define N 200005
int t[N],a[N];
vector<int> v[N];
struct Node{int v,id;};
Node b[N];
bool cmp(Node x,Node y)
{
	if(x.v!=y.v) return x.v<y.v;
	return x.id<y.id;
}
bool cmp2(Node x,Node y)
{
	if(x.v!=y.v) return x.v>y.v;
	return x.id>y.id;
}
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) t[i]=a[i]=read();
	sort(t+1,t+n+1); int S=unique(t+1,t+n+1)-t-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(t+1,t+S+1,a[i])-t;
	for(int i=1;i<=n;i++) v[a[i]].pb(i);
	for(int i=1;i<=n;i++) b[i]={a[i],i};
	sort(b+1,b+n+1,cmp);
	// for(int i=1;i<=n;i++) printf("%d %d\n",b[i].id,b[i].v);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(j<n&&b[j+1].id>b[j].id) j++;
		int d=b[j].v,e=b[i].v;
		// printf("%d %d\n",e-1,b[i].id);
		// printf("%d %d %d %d\n",i,j,(v[d+1].end()-lower_bound(v[d+1].begin(),v[d+1].end(),b[j].id)),(lower_bound(v[e-1].begin(),v[e-1].end(),b[i].id)-v[e-1].begin()));
		int cnt=j-i+1+(v[d+1].end()-lower_bound(v[d+1].begin(),v[d+1].end(),b[j].id))+(lower_bound(v[e-1].begin(),v[e-1].end(),b[i].id)-v[e-1].begin());
		// if((lower_bound(v[e-1].begin(),v[e-1].end(),b[i].id)-v[e-1].begin())) cnt--;
		if(cnt>ans) ans=cnt;
		i=j;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(int)v[i].size();j++)
		{
			int R=j+1+(v[i+1].end()-lower_bound(v[i+1].begin(),v[i+1].end(),v[i][j]));
			if(R>ans) ans=R;
		}
	}
	for(int i=1;i<=n;i++) v[i].clear();
	cout<<n-ans<<endl;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}