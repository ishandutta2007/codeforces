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
#define N 65
char a[N][N];
int sl[N],sc[N];
void work()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	bool a0=1,no=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='A') no=0;
			else a0=0;
		}
	}
	if(no)
	{
		cout<<"MORTAL\n";
		return ;
	}
	if(a0)
	{
		cout<<"0\n";
		return ;
	}
	for(int i=1;i<=n;i++) sc[i]=0;
	for(int i=1;i<=m;i++) sl[i]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) sc[i]+=a[i][j]=='A';
	}
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++) sl[j]+=a[i][j]=='A';
	}
	if(sc[1]==m||sc[n]==m||sl[1]==n||sl[m]==n)
	{
		cout<<"1\n";
		return ;
	}
	if(a[1][1]=='A'||a[1][m]=='A'||a[n][1]=='A'||a[n][m]=='A')
	{
		cout<<"2\n";
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(sc[i]==m)
		{
			cout<<"2\n";
			return ;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(sl[i]==n)
		{
			cout<<"2\n";
			return ;
		}
	}
	if(sc[1]||sc[n]||sl[1]||sl[m])
	{
		cout<<"3\n";
		return ;
	}
	cout<<"4\n";
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//