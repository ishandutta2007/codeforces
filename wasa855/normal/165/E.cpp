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
#define N (1<<22)
#define INF (N-1)
int a[N],ans[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<N;i++) ans[i]=-1;
	for(int i=1;i<=n;i++)
	{
		ans[a[i]^INF]=a[i];
	}
	for(int i=N-1;i>=0;i--)
	{
		if(ans[i]==-1)
		{
			for(int j=0;j<=21;j++)
			{
				if((i&(1<<j))==0)
				{
					if(ans[i|(1<<j)]!=-1)
					{
						ans[i]=ans[i|(1<<j)];
						break;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",ans[a[i]]);
	}
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}