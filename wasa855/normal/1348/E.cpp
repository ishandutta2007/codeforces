#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define int long long
typedef pair<int,int> pii;
inline int min(int j,int y,int z){return min(j,min(y,z));}
inline int max(int j,int y,int z){return max(j,max(y,z));}
inline int add(int j,int y){return j+y>=mod?j+y-mod:j+y;}
inline int add(int j,int y,int z){return add(add(j,y),z);}
inline int sub(int j,int y){return j-y<0?j-y+mod:j-y;}
inline int mul(int j,int y){return 1LL*j*y%mod;}
inline int mul(int j,int y,int z){return mul(mul(j,y),z);}
#define N 505
signed a[N],b[N];
int f[N][N];
signed r[N][N];
signed main()
{
	signed n,k; cin>>n>>k;
	for(signed i=1;i<=n;i++) a[i]=read(),b[i]=read();
	for(signed i=0;i<=n;i++) for(signed j=0;j<k;j++) f[i][j]=-INF;
	f[0][0]=0;
	for(signed i=1;i<=n;i++)
	{
		for(signed j=0;j<k;j++)
		{
			for(signed c=0;c<k;c++)
			{
				if(a[i]<c) break;
				signed A=a[i]-c;
				signed T=(k-A%k); if(T>=k) T-=k;
				signed B=b[i]-T;
				if(B<0) continue;
				int R=f[i-1][j]+((j+c)>=k?1:0)+(r[i-1][j]+T+A+B)/k;
				signed _r=(r[i-1][j]+B)%k;
				signed pos=(j+c)%k;
				if(R>f[i][pos]) f[i][pos]=R,r[i][pos]=_r;
				else if(R==f[i][pos]&&_r>r[i][pos]) r[i][pos]=_r;
			}
		}
	}
	// for(int i=1;i<=n;i++)
	// {
		// for(int j=0;j<k;j++) printf("%d %d : %d %d\n",i,j,f[i][j],r[i][j]);
	// }
	int ans=0;
	for(int i=0;i<k;i++) if(f[n][i]>ans) ans=f[n][i];
	cout<<ans<<endl;
	return 0;
}