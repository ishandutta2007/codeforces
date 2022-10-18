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
#define N 85
int a[N],ans[N*N],f[N][N][N*N],b[N],n,m;
signed main()
{
	cin>>n; for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) if(a[i]==1) b[++m]=i;
	int l=n*(n-1)/2;
	for(int i=0;i<=n;i++) for(int j=0;j<=m;j++) for(int k=0;k<=l;k++) f[i][j][k]=-inf;
	f[0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=0;k<=l;k++)
			{
				if(k<abs(i-b[j])) continue;
				for(int c=0;c<i;c++)
				{
					// if(j<1||k<abs(i-b[j])) continue;
					int R=f[c][j-1][k-abs(i-b[j])]+(i-c-1)*(n-i-m+j);
					f[i][j][k]=max(f[i][j][k],R);
				}
			}
		}
	}
	// for(int i=0;i<=n;i++)
	// {
		// for(int j=0;j<=m;j++) for(int k=0;k<=l;k++) printf("%d %d %d - %d\n",i,j,k,f[i][j][k]);;
	// }
	for(int j=0;j<=n;j++) for(int i=0;i<=l;i++) ans[i]=max(ans[i],f[j][m][i]);
	for(int i=1;i<=l;i++) ans[i]=max(ans[i],ans[i-1]);
	for(int i=0;i<=l;i++) printf("%d%c",ans[i]," \n"[i==l]);
	return 0;
}