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
#define N 1005
int a[N][N],n;
int cnt[N][N];
struct Node
{
	int id,col;
	Node(int a=0,int b=0) {id=a,col=b;}
};
int ans[N];
queue<Node> q;
void fix(int go)
{
	ans[go]=1;
	for(int j=1;j<=n*2;j++)
	{
		if(ans[j]) continue;
		for(int k=1;k<=n;k++) if(a[go][k]==a[j][k])
		{
			ans[j]=-1;
			for(int c=1;c<=n;c++) cnt[a[j][c]][c]--;
			break;
		}
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(cnt[i][j]==1) q.emplace(i,j),cnt[i][j]--;
}
void work()
{
	memset(cnt,0,sizeof(cnt)),memset(ans,0,sizeof(ans));
	cin>>n;
	for(int i=1;i<=n*2;i++) for(int j=1;j<=n;j++) a[i][j]=read(),cnt[a[i][j]][j]++;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(cnt[i][j]==1) q.emplace(i,j),cnt[i][j]--;
	int sum=1;
	for(int i=1;i<=n*n;i++)
	{
		int id,col;
		// printf("%d\n",q.empty());
		if(q.empty())
		{
			sum=add(sum,sum);
			int un=0;
			for(int i=1;i<=n*2;i++) if(ans[i]==0) {un=i; break;}
			// cout<<un<<endl;
			id=a[un][1],col=1,cnt[id][col]--;
			fix(un);
		}
		else
		{
			id=q.front().id,col=q.front().col; q.pop();
		}
		// printf("%d %d\n",id,col);
		int go=0;
		for(int i=1;i<=n*2;i++) if(a[i][col]==id&&ans[i]!=-1) go=i;
		if(ans[go]==0) fix(go);
	}
	cout<<sum<<endl;
	for(int i=1;i<=n*2;i++) if(ans[i]==1) printf("%d ",i);
	cout<<"\n";
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}