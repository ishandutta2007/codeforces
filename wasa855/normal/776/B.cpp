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
#define N 100005
int n;
int vis[N];
int prim[N];
int cnt;
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n;
	if(n==1)
	{
		printf("1\n1\n");
		return 0;
	}
	if(n==2)
	{
		printf("1\n1 1\n");
		return 0;
	}
	n++;
	printf("%d\n",2);
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			prim[++cnt]=i;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(i*prim[j]>n) break;
			vis[i*prim[j]]=1;
			if(i%prim[j]==0) break;
		}
	}
	for(int i=2;i<=n;i++)
	{
		printf("%d ",vis[i]+1);
	}
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}