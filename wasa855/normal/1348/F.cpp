#include<bits/stdc++.h>
using namespace std;
#define pb push_back
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 200005
int l[N],r[N],ans[N],n;
vector<pii> v[N];
int id[N];
int lowbit(int u){return u&(-u);}
struct bit
{
	int t[N];
	void init()
	{
		for(int i=1;i<=n;i++) t[i]=inf;
	}
	void update(int p,int v)
	{
		while(p<=n) t[p]=min(t[p],v),p+=lowbit(p);
	}
	int query(int p)
	{
		int ans=inf;
		while(p) ans=min(ans,t[p]),p-=lowbit(p);
		return ans;
	}
}t;
signed main()
{
	cin>>n; t.init();
	for(int i=1;i<=n;i++)
	{
		l[i]=read(),r[i]=read();
		v[l[i]].emplace_back(r[i],i);
	}
	priority_queue<pii,vector<pii>,greater<pii>> q;
	for(int i=1;i<=n;i++)
	{
		for(pii u:v[i]) q.push(u);
		if(!q.empty()&&q.top().first>=i)
		{
			ans[q.top().second]=i;
			id[i]=q.top().second;
			q.pop();
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(t.query(r[id[i]])<=i)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(l[id[j]]<=i)
				{
					cout<<"NO\n";
					for(int i=1;i<=n;i++) printf("%d ",ans[i]); cout<<"\n";
					swap(ans[id[i]],ans[id[j]]);
					for(int i=1;i<=n;i++) printf("%d ",ans[i]); cout<<"\n";
					return 0;
				}
			}
		}
		t.update(i,l[id[i]]);
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++) printf("%d ",ans[i]); cout<<"\n";
	return 0;
}