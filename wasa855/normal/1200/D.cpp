#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 2005
int a[N][N];
bool u1[N],u2[N];
int l[N][N],r[N][N],u[N][N],d[N][N];
int sa[N][N],sb[N][N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	char xx[N];
	for(int i=1;i<=n;i++)
	{
		scanf("%s",xx+1);
		for(int j=1;j<=n;j++)
		{
			if(xx[j]=='W') a[i][j]=0;
			else a[i][j]=1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		u1[i]=true;
		for(int j=1;j<=n;j++)
		{
			if(a[i][j]==1) u1[i]=false;
		}
		if(u1[i]) ans++;
	}
	for(int i=1;i<=n;i++)
	{
		u2[i]=true;
		for(int j=1;j<=n;j++)
		{
			if(a[j][i]==1) u2[i]=false;
		}
		if(u2[i]) ans++;
	}
	for(int i=1;i<=n;i++)
	{
		l[i][0]=true;
		l[i][1]=true;
		for(int j=2;j<=n;j++)
		{
			if(l[i][j-1]==false) l[i][j]=false;
			else if(a[i][j-1]==1) l[i][j]=false;
			else l[i][j]=true;
		}
	}
	for(int i=1;i<=n;i++)
	{
		r[i][n+1]=true;
		r[i][n]=true;
		for(int j=n-1;j>=1;j--)
		{
			if(r[i][j+1]==false) r[i][j]=false;
			else if(a[i][j+1]==1) r[i][j]=false;
			else r[i][j]=true;
		}
	}
	for(int i=1;i<=n;i++)
	{
		u[0][i]=true;
		u[1][i]=true;
		for(int j=2;j<=n;j++)
		{
			if(u[j-1][i]==false) u[j][i]=false;
			else if(a[j-1][i]==1) u[j][i]=false;
			else u[j][i]=true;
		}
	}
	
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			printf("%d ",u[i][j]);
//		}
//		cout<<"\n";
//	}
	
	for(int i=1;i<=n;i++)
	{
		d[n+1][i]=true;
		d[n][i]=true;
		for(int j=n-1;j>=1;j--)
		{
			if(d[j+1][i]==false) d[j][i]=false;
			else if(a[j+1][i]==1) d[j][i]=false;
			else d[j][i]=true;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(u1[i]) continue;
		for(int j=1;j<=n-k+1;j++)
		{
			if(l[i][j]&&r[i][j+k-1])
			{
				sa[max(1,i-k+1)][j]++;
				sa[i+1][j]--;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(u2[i]) continue;
		for(int j=1;j<=n-k+1;j++)
		{
			if(u[j][i]&&d[j+k-1][i])
			{
				sb[j][max(1,i-k+1)]++;
				sb[j][i+1]--;
			}
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			printf("%d ",sa[i][j]);
//		}
//		cout<<"\n";
//	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			sa[i][j]+=sa[i-1][j];
			sb[i][j]+=sb[i][j-1];
		}
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
//			printf("%d ",sb[i][j]);
			if(sa[i][j]+sb[i][j]>maxn)
			{
				maxn=sa[i][j]+sb[i][j];
			}
		}
//		cout<<"\n";
	}
//	cout<<ans<<endl;
	cout<<maxn+ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//sacefaf