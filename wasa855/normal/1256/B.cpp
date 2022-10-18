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
#define N 105
int a[N];
bool vis[N];
void work()
{
	memset(vis,0,sizeof(vis));
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	int pre=1;
	for(int i=1;i<=n;i++)
	{
		int minn=n+1,cur=0;
		for(int j=i;j<=n;j++)
		{
			if(a[j]<minn) minn=a[j],cur=j;
		}
		for(int j=cur-1;j>=i;j--) swap(a[j+1],a[j]),vis[j]=1;
		while(i>1&&a[i-1]>a[i]&&vis[i-1]==0) vis[i-1]=1,swap(a[i],a[i-1]),i--;
		i=cur;
//		for(int i=1;i<=n;i++) printf("%d ",a[i]);
//		cout<<"\n";
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	cout<<"\n";
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