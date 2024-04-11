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
#define N 400005
#define M (1<<21)
int a[N],f[M];
int p[25][25];
int cnt[25];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read()-1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<20;j++)
		{
			p[a[i]][j]+=cnt[j];
		}
		cnt[a[i]]++;
	}
//	for(int i=0;i<20;i++)
//	{
//		for(int j=0;j<20;j++)
//		{
//			printf("%lld ",p[i][j]);
//		}
//		cout<<"\n";
//	}
	memset(f,0x3f,sizeof(f));
	f[0]=0; int lim=1<<20;
	for(int i=1;i<lim;i++)
	{
		for(int j=0;j<20;j++)
		{
			if(i&(1<<j))
			{
				int tmp=0;
				for(int k=0;k<20;k++)
				{
					if(!(i&(1<<k))) tmp+=p[j][k];
				}
				if(f[i^(1<<j)]+tmp<f[i]) f[i]=f[i^(1<<j)]+tmp;
			}
		}
	}
	cout<<f[lim-1]<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}