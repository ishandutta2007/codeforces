#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 1005
int n,m,d;
int c[N];
int ans[N];
int res[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>m>>d;
	int len=0;
	for(int i=1;i<=m;i++)
	{
		c[i]=read();
		len+=c[i];
	}
	int jum=(d-1)*(m+1);
	if(jum+len>=n)
	{
		cout<<"YES\n";
		int dj=(n-len)/(m+1);
		int ml=(n-len)%(m+1);
//		cout<<ml<<endl;
		int cur=0,cnt=0;
		for(int i=1;i<=m;i++)
		{
			if(cnt<ml)
			{
				cnt++;
				ans[i]=cur+dj+2;
				cur+=dj+1+c[i];
			}
			else ans[i]=cur+dj+1,cur+=dj+c[i];
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=ans[i];j<=ans[i]+c[i]-1;j++)
			{
				res[j]=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			printf("%d ",res[i]);
		}
		cout<<"\n";
	}
	else
	{
		cout<<"NO\n";
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}