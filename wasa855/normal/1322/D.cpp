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
int lowbit(int x) {return x&(-x);}
#define N 4005
int a[N],v[N],pre[N],s[N],cnt[N],n,m;
int f[N][N],lim[N],lg[N];
signed main()
{
	for(int i=1;i<N;i++) lg[i]=lg[i/2]+1;
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) s[i]=read();
	for(int i=1;i<=n+m;i++) v[i]=read();
	for(int i=1;i<=n+m;i++) pre[i]=pre[i-1]+v[i];
	for(int i=0;i<=m;i++) for(int j=0;j<=n;j++) f[i][j]=-inf;
	reverse(a+1,a+n+1),reverse(s+1,s+n+1);
	f[0][0]=0,lim[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i];j>=max(0,a[i]-13);j--)
		{
			for(int k=n;k>=0;k--)
			{
				int hav=k>>(a[i]-j); hav++;
				int go=lg[lowbit(hav)];
//				printf("$ %d %d - %d - %d\n",j,k,hav,f[i][j]-s[i]);
				f[a[i]][hav]=max(f[a[i]][hav],f[j][k]-s[i]+pre[a[i]+go-1]-pre[a[i]-1]);
			}
		}
		int tmp=-inf;
		for(int j=0;j<a[i]-13;j++) tmp=max(tmp,lim[j]);
		f[a[i]][1]=max(f[a[i]][1],tmp-s[i]+v[a[i]]);
		for(int j=0;j<=n;j++) lim[a[i]]=max(lim[a[i]],f[a[i]][j]);
//		printf("%d :\n",i);
//		for(int j=0;j<=m;j++) for(int k=0;k<=n;k++) printf("%d%c",f[j][k]," \n"[k==n]);
	}
	int ans=0;
	for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) ans=max(ans,f[i][j]);
	cout<<ans<<endl;
	return 0;
}