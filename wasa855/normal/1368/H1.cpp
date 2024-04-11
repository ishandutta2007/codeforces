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
inline char rdchar()
{
	char ch=getchar();
	while(!(ch>='a'&&ch<='z')&&!(ch>='A'&&ch<='Z')&&!(ch>='0'&&ch<='9')) ch=getchar();
	return ch;
}
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 100005
int l[N],r[N],u[N],d[N];
int l1,r1,u1,d1;
int n,m,Q;
int f[N][2];
signed main()
{
	cin>>n>>m>>Q; assert(Q==0);
	for(int i=1;i<=n;i++) l[i]=rdchar()=='B';
	for(int i=1;i<=n;i++) r[i]=rdchar()=='B';
	for(int i=1;i<=m;i++) u[i]=rdchar()=='B';
	for(int i=1;i<=m;i++) d[i]=rdchar()=='B';
	for(int i=1;i<=n;i++) l1+=l[i],r1+=r[i];
	for(int i=1;i<=m;i++) u1+=u[i],d1+=d[i];
	f[0][0]=l1,f[0][1]=n-l1;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<2;j++)
		{
			f[i][j]=min(f[i-1][j]+(u[i]!=j)+(d[i]!=j),f[i-1][j^1]+n+(u[i]!=j)+(d[i]!=j));
			// printf("%d %d %d %d\n",i,j,f[i-1][j]+(u[i]!=j)+(d[i]!=j),f[i-1][j^1]+n+(u[i]!=j)+(d[i]!=j));
		}
	}
	f[m+1][0]=min(f[m][0]+r1,f[m][1]+n+r1);
	f[m+1][1]=min(f[m][1]+n-r1,f[m][0]+n+n-r1);
	int ans1=min(f[m+1][0],f[m+1][1]);
	// for(int i=1;i<=m;i++) printf("%d %d\n",f[i][0],f[i][1]);
	
	f[0][0]=u1,f[0][1]=m-u1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<2;j++)
		{
			f[i][j]=min(f[i-1][j]+(l[i]!=j)+(r[i]!=j),f[i-1][j^1]+m+(l[i]!=j)+(r[i]!=j));
		}
	}
	f[n+1][0]=min(f[n][0]+d1,f[n][1]+m+d1);
	f[n+1][1]=min(f[n][1]+m-d1,f[n][0]+m+m-d1);
	int ans2=min(f[n+1][0],f[n+1][1]);
	cout<<min(ans1,ans2)<<endl;
	return 0;
}