#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100005
#define M 65
int sum[M];
int a[N];
#define LIM 305
int d[LIM][LIM],mp[LIM][LIM];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]==0)
		{
			i--;
			n--;continue;
		}
		for(int j=0;j<=60;j++)
		{
			if(a[i]&(1LL<<j))
			{
//				printf("%d %d\n",i,j);
				sum[j]++;
			}
		}
	}
	for(int i=0;i<=60;i++)
	{
		if(sum[i]>=3)
		{
//			cout<<sum[i]<<endl;
			cout<<3<<endl;
			return 0;
		}
	}
//	cout<<n<<endl;
//	cout<<"ZHI\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			mp[i][j]=d[i][j]=N;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[i]&a[j])
			{
				mp[i][j]=d[i][j]=1;
			}
		}
	}
	int ans=N;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)
		{
			for(int j=i+1;j<k;j++)
			{
				if(d[i][j]+mp[i][k]+mp[k][j]<ans)
				{
					ans=d[i][j]+mp[i][k]+mp[k][j];
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(d[i][k]+d[k][j]<d[i][j])
				{
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}
	if(ans==N) cout<<"-1\n";
	else cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//aswf