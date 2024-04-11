#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans; return ans;
}
#define N 500005
string a[N];
int sx[N],sy[N];
void work()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) sx[i]=0;
	for(int i=0;i<m;i++) sy[i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j]=='*') sx[i]++;
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[j][i]=='*') sy[i]++;
		}
	}
//	for(int i=1;i<=n;i++) printf("%d ",sx[i]);
//	cout<<"\n";
//	for(int i=0;i<m;i++) printf("%d ",sy[i]);
//	cout<<"\n";
	int res=n*m;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x=n+m-sx[i]-sy[j];
			if(a[i][j]=='.') x--;
			if(x<res) res=x;
		}
	}
	cout<<res<<endl;
}
signed main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int T;
	cin>>T;
	while(T--) work();
#ifndef ONLINE_JUDGE
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//casefaw