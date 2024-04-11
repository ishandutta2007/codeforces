#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 505
char s[N][N];
int sr[N][N],sg[N][N],sy[N][N],sb[N][N];
bool v[N][N][N];
int sum[N][N][N/2];
int n,m,Q;
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
//	printf("%lf\n",sizeof(sum)/1024.0/1024.0);
	cin>>n>>m>>Q;
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			sr[i][j]=sr[i-1][j]+sr[i][j-1]-sr[i-1][j-1];
			sg[i][j]=sg[i-1][j]+sg[i][j-1]-sg[i-1][j-1];
			sy[i][j]=sy[i-1][j]+sy[i][j-1]-sy[i-1][j-1];
			sb[i][j]=sb[i-1][j]+sb[i][j-1]-sb[i-1][j-1];
			if(s[i][j]=='R') sr[i][j]++;
			if(s[i][j]=='G') sg[i][j]++;
			if(s[i][j]=='Y') sy[i][j]++;
			if(s[i][j]=='B') sb[i][j]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int lim=min(n-i+1,m-j+1)/2;
			for(int k=1;k<=lim;k++)
			{
				bool ok=1;
				if(sr[i+k-1][j+k-1]-sr[i-1][j+k-1]-sr[i+k-1][j-1]+sr[i-1][j-1]!=k*k) ok=0;
				if(sg[i+k-1][j+2*k-1]-sg[i-1][j+2*k-1]-sg[i+k-1][j+k-1]+sg[i-1][j+k-1]!=k*k) ok=0;
				if(sy[i+2*k-1][j+k-1]-sy[i+k-1][j+k-1]-sy[i+2*k-1][j-1]+sy[i+k-1][j-1]!=k*k) ok=0;
				if(sb[i+2*k-1][j+2*k-1]-sb[i+k-1][j+k+k-1]-sb[i+k+k-1][j-1+k]+sb[i-1+k][j+k-1]!=k*k) ok=0;
				if(ok)
				{
					v[i][j][k]=1;
//					printf("%d %d %d\n",i,j,k);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=max(n,m)/2;k++)
			{
				sum[i][j][k]=sum[i-1][j][k]+sum[i][j-1][k]-sum[i-1][j-1][k]+v[i][j][k];
			}
		}
	}
	while(Q--)
	{
		int r1=read(),c1=read(),r2=read(),c2=read();
		int ans=0;
		for(int i=1;i<=max(n,m)/2;i++)
		{
			if(r2-i-i+1<r1) break;
			if(c2-i-i+1<c1) break;
			int x=sum[r2-i-i+1][c2-i-i+1][i]-sum[r1-1][c2-i-i+1][i]-sum[r2-i-i+1][c1-1][i]+sum[r1-1][c1-1][i];
			if(x) ans=i;
		}
		printf("%d\n",ans*ans*4);
	}
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}