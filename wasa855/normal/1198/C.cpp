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
#define N 500005
bool vis[N];
bool used[N];
int u[N],v[N];
void work()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=3*n;i++) vis[i]=false;
	for(int i=1;i<=m;i++) used[i]=false;
	for(int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read();
	}
	int cnt=0;
	for(int i=1;i<=m;i++)
	{
		if(vis[u[i]]==false&&vis[v[i]]==false)
		{
			vis[u[i]]=true,vis[v[i]]=true;
			used[i]=true;
			cnt++;
		}
	}
	if(cnt>=n)
	{
		cout<<"Matching\n";
		cnt=0;
		for(int i=1;i<=m;i++)
		{
			if(used[i]&&cnt<n) printf("%d ",i),cnt++;
		}
		cout<<"\n";
	}
	else
	{
		cout<<"IndSet\n";
		cnt=0;
		for(int i=1;i<=n*3;i++)
		{
			if(!vis[i]&&cnt<n) cnt++,printf("%d ",i);
		}
		cout<<"\n";
	}
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