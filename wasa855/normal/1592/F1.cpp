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
inline char rdchar()
{
	char ch=getchar();
	while(!(ch>='a'&&ch<='z')&&!(ch>='A'&&ch<='Z')&&!(ch>='0'&&ch<='9')) ch=getchar();
	return ch;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 505
int a[N][N],f[N][N],w[N][N],n,m;
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]=rdchar()=='B';
	int ans=0;
	for(int i=n;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		{
			int pre=w[i+1][j]^w[i][j+1]^w[i+1][j+1];
			if(a[i][j]^pre) f[i][j]=1,ans++;
			w[i][j]=pre^f[i][j];
		}
	}
	for(int i=1;i<n;i++) for(int j=1;j<m;j++) if(f[i][j]&&f[i][m]&&f[n][j]&&f[n][m]) f[n][m]^=1,ans--;
	cout<<ans<<endl;
	return 0;
}