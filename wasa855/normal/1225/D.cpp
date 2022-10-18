#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100005
#define LIM 100000LL
int kasumi(int x,int y)
{
	int ans=1;
	for(int i=1;i<=y;i++)
	{
		ans*=x;
		if(ans>LIM) return ans;
	}
	return ans;
}
int tbl[N];
int a[N];
int sum[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) a[i]=read();
	int m=0;
	for(int i=1;;i++)
	{
		tbl[i]=kasumi(i,k);
		if(tbl[i]>LIM)
		{
			m=i-1;break;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int ned=1;
		int cur=a[i];
		for(int j=2;j*j<=cur;j++)
		{
			int cnt=0;
			while(cur%j==0) cur/=j,cnt++;
			if(cnt%k!=0)
			{
				for(int c=cnt%k+1;c<=k;c++)
				{
					ned=ned*j;
					if(ned>LIM) break;
				}
			}
			if(ned>LIM) break;
		}
		if(cur!=1&&ned<=LIM)
		{
			for(int j=2;j<=k;j++)
			{
				ned=ned*cur;
				if(ned>LIM) break;
			}
		}
//		cout<<ned<<endl;
		if(ned<=LIM)
		{
			for(int j=1;j<=m;j++)
			{
				if(ned*tbl[j]<=LIM)
				{
					ans+=sum[ned*tbl[j]];
				}
				else break;
			}
		}
		sum[a[i]]++;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}