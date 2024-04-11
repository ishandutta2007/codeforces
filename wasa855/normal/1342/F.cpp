#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 17
int a[N],sum[1<<N];
int pl[1<<N];
int f[N][1<<N][N];
int fx[N][1<<N][N],fy[N][1<<N][N];
void work()
{
	int n=read();
	for(int i=0;i<n;i++) a[i]=read();
	int lim=1<<n;
	for(int i=0;i<lim;i++)
	{
		sum[i]=0;
		for(int j=0;j<n;j++) if(i&(1<<j)) sum[i]+=a[j];
	}
	// for(int i=0;i<lim;i++) printf("%d ",sum[i]); cout<<"\n";
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<lim;j++)
		{
			for(int k=0;k<=n;k++) f[i][j][k]=inf;
		}
	}
	f[0][0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<lim;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(f[i][j][k]==inf) continue;
				int QaQ=j^(lim-1);
				for(int c=j^(lim-1);c!=0;c=QaQ&(c-1))
				{
					if(sum[c]<=f[i][j][k]) continue;
					if(!(c>>k)) continue;
					int qaq=pl[c>>k]+k+1;
					// cout<<qaq<<endl;
					if(f[i+1][j|c][qaq]>sum[c])
					{
						f[i+1][j|c][qaq]=sum[c];
						fx[i+1][j|c][qaq]=j;
						fy[i+1][j|c][qaq]=k;
					}
				}
			}
		}
	}
	// for(int i=0;i<=n;i++)
	// {
		// for(int j=0;j<lim;j++)
		// {
			// for(int k=0;k<=n;k++) printf("%d ",f[i][j][k]);
			// cout<<"\n";
		// }
	// }
	int ans=0,pl;
	for(int i=0;i<=n;i++)
	{
		for(int k=0;k<=n;k++)
		{
			if(f[i][lim-1][k]<inf) ans=i,pl=k;
		}
	}
	// printf("%d %d\n",ans,pl);
	vector<pii> A;
	int cj=lim-1,ck=pl;
	for(int i=ans;i;i--)
	{
		int tj=fx[i][cj][ck],tk=fy[i][cj][ck];
		for(int j=0;j<n;j++)
		{
			if(((tj^cj)&(1<<j))&&(j+1!=ck)) A.emplace_back(j,ck-1);
		}
		cj=tj,ck=tk;
	}
	cout<<A.size()<<endl;
	for(int i=0;i<(int)A.size();i++)
	{
		int x=A[i].fir,y=A[i].sec;
		for(int j=0;j<i;j++) if(A[j].fir<A[i].fir) x--;
		for(int j=0;j<i;j++) if(A[j].fir<A[i].sec) y--;
		printf("%d %d\n",x+1,y+1);
	}
}
signed main()
{
	int lim=1<<16;
	for(int i=1;i<lim;i++)
	{
		if(i&1) pl[i]=0;
		else pl[i]=pl[i>>1]+1;
	}
	int T=read();
	while(T--) work();
 	return 0;
}