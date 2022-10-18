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
#define N 505
int a[N],b[N];
vector<int> v[N];
int get(int n)
{
	int res=0;
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(a[i]>a[j]) res++;
	return res;
}
vector<int> ans;
void shift(int i)
{
	ans.pb(i);
	int x=a[i],y=a[i+1],z=a[i+2];
	a[i]=z,a[i+1]=x,a[i+2]=y;
}
void work()
{
	int n=read();
	for(int i=1;i<=500;i++) v[i].clear();
	for(int i=1;i<=n;i++) a[i]=read(),v[a[i]].pb(i);
	int cnt=0;
	for(int i=1;i<=500;i++)
	{
		for(int j:v[i]) a[j]=++cnt;
	}
	ans.clear();
	int r=get(n);
	if(r&1)
	{
		for(int i=1;i<=500;i++)
		{
			if(v[i].size()>=2)
			{
				swap(a[v[i][0]],a[v[i][1]]);
				break;
			}
		}
	}
	if(get(n)&1) {cout<<"-1\n"; return ;}
	for(int i=1;i<=n;i++)
	{
		int minn=i;
		for(int j=i;j<=n;j++)
		{
			if(a[j]<a[minn]) minn=j;
		}
		if(minn==i) continue;
		while(minn>i)
		{
			if(minn==i+1) shift(i),shift(i),minn--;
			else shift(minn-2),minn-=2;
		}
	}
	cout<<ans.size()<<endl;
	for(int i:ans) printf("%d ",i);
	cout<<"\n";
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}