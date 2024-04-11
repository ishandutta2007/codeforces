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
#define M 25
#define N (1<<20)
int f[N],g[N];
int cnt[M][M];
string s;
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<n;i++)
	{
		int u=s[i-1]-'a',v=s[i]-'a';
		cnt[u][v]++;
		cnt[v][u]++;
	}
	int lim=1<<m;
	for(int i=0;i<lim;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(!(i>>j&1)) continue;
			for(int k=0;k<m;k++)
			{
				if(i>>k&1) continue;
				g[i]+=cnt[j][k];
			}
		}
//		cout<<g[i]<<endl;
	}
//	for(int i=0;i<m;i++)
//	{
//		for(int j=0;j<m;j++)
//		{
//			printf("%d ",cnt[i][j]);
//		}
//		cout<<"\n";
//	}
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=0;i<lim;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(i>>j&1) continue;
			if(f[i|(1<<j)]>f[i]+g[i])
			{
				f[i|(1<<j)]=f[i]+g[i];
			}
		}
	}
	cout<<f[lim-1]<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}