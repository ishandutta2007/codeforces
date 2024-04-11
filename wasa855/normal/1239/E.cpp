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
#define N 26
#define M 50005
int a[N*2],f[N][N*M],fr[N][N*M],vis[N*2],n;
signed main()
{
	cin>>n; for(int i=1;i<=n*2;i++) a[i]=read();
	sort(a+1,a+n*2+1);
	f[0][0]=1; int sum=0;
	for(int i=3;i<=n*2;i++)
	{
		for(int j=n-1;j>=0;j--) for(int k=0;k<=sum;k++) if(f[j][k]&&!f[j+1][k+a[i]])
		{
			f[j+1][k+a[i]]=1;
			fr[j+1][k+a[i]]=i;
		}
		sum+=a[i];
	}
	int minn=inf,id=0;
	for(int i=0;i<=sum;i++) if(f[n-1][i])
	{
		if(max(i,sum-i)<minn) minn=max(i,sum-i),id=i;
	}
	// for(int i=1;i<n;i++) for(int j=0;j<=sum;j++) printf("%d%c",fr[i][j]," \n"[j==sum]);
	vector<int> v1,v2;
	int cur=id;
	for(int i=n-1;i>=1;i--)
	{
		v1.pb(fr[i][cur]);
		vis[fr[i][cur]]=1;
		// cout<<fr[i][cur]<<endl;
		cur-=a[fr[i][cur]];
	}
	for(int i=3;i<=n*2;i++) if(!vis[i]) v2.pb(i);
	printf("%d ",a[1]);
	reverse(v1.begin(),v1.end());
	for(int i=0;i<(int)v1.size();i++) printf("%d%c",a[v1[i]]," \n"[i==(int)v1.size()-1]);
	// reverse(v2.begin(),v2.end());
	for(int i=(int)v2.size()-1;i>=0;i--) printf("%d ",a[v2[i]]);
	printf("%d\n",a[2]);
	return 0;
}