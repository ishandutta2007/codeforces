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
#define N 6005
int x[N],y[N],n;
int get(int dx,int dy)
{
	dx=abs(dx),dy=abs(dy);
	if(dx%4==0&&dy%4==0) return 0;
	else return 1;
}
int cnt[N][2][2];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		x[i]=read(),y[i]=read();
		cnt[i][x[i]/2%2][y[i]/2%2]++;
	}
	for(int i=n;i>=1;i--) for(int j=0;j<2;j++) for(int k=0;k<2;k++) cnt[i][j][k]+=cnt[i+1][j][k];
	// printf("%d %d\n",c1,c2);
	// ll ans1=c1*(c1-1)*(c1-2)/6;
	// ll ans2=c1*(c1-1)
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int dx=x[i]-x[j],dy=y[i]-y[j];
			if(!get(dx,dy))
			{
				// printf("%d %d\n",i,j);
				ans+=n-2;
				// ans-=cnt[1][x[i]/2%2][y[i]/2%2];
			}
		}
	}
	for(int i=0;i<2;i++) for(int j=0;j<2;j++)
	{
		int r=cnt[1][i][j]*(cnt[1][i][j]-1)*(cnt[1][i][j]-2)/6;
		ans-=r*2;
	}
	cout<<ans<<endl;
	return 0;
}