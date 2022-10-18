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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 300005
map<int,int> las,f[N];
int a[N],b[N];
int p1[N],p2[N],p3[N],n;
int dfs(int x,int y)
{
	if(x<0||y<0) return -inf;
	if(x<=0&&y<=0) return 0;
	if(f[x].find(y)!=f[x].end()) return f[x][y];
	int ans=0;
	if(p1[x]>p2[y]) ans=max(ans,dfs(p1[x],y)+1);
	else ans=max(ans,dfs(x,p2[y])+1);
	if(x>0&&y>0) ans=max(ans,dfs(p3[min(x,y)],p3[min(x,y)])+1);
	f[x][y]=ans;
	return ans;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	p1[0]=p2[0]=p3[0]=-1;
	las.clear();
	las[0]=0; int sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		if(las.find(sum)!=las.end()) p1[i]=las[sum];
		else p1[i]=-1;
		las[sum]=i;
	}
	for(int i=1;i<=n;i++) p1[i]=max(p1[i],p1[i-1]);
	las.clear();
	las[0]=0; sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=b[i];
		if(las.find(sum)!=las.end()) p2[i]=las[sum];
		else p2[i]=-1;
		las[sum]=i;
	}
	for(int i=1;i<=n;i++) p2[i]=max(p2[i],p2[i-1]);
	las.clear();
	las[0]=0; sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i]+b[i];
		if(las.find(sum)!=las.end()) p3[i]=las[sum];
		else p3[i]=-1;
		las[sum]=i;
	}
	for(int i=1;i<=n;i++) p3[i]=max(p3[i],p3[i-1]);
	cout<<dfs(n,n)<<endl;
	// for(int i=1;i<=n;i++) for(auto [x,y]:f[i]) printf("%d %d : %d\n",i,x,y);
	return 0;
}