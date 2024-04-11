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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
inline int add(int x,int y) {return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z) {return add(add(x,y),z);}
inline int sub(int x,int y) {return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y) {return 1LL*x*y%mod;}
inline int mul(int x,int y,int z) {return mul(mul(x,y),z);}
#define N 500005
int x[N],y[N],fa[N],n,m;
int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int op=read(); x[i]=read();
		if(op==2) y[i]=read();
		else y[i]=0;
	}
	for(int i=0;i<=m;i++) fa[i]=i;
	vector<int> ans; int sum=1;
	for(int i=1;i<=n;i++)
	{
		int u=find(x[i]),v=find(y[i]);
		if(u!=v) ans.pb(i),sum=mul(sum,2),fa[u]=v;
	}
	printf("%d %d\n",sum,(int)ans.size());
	print(ans);
	return 0;
}