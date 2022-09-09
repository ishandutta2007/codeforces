#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505;
const int mod=998244353;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
int mul(int x, int y){ return (ll)x*y%mod;}
int powmod(int x, int k){ int ans=1;for(;k;k>>=1,x=mul(x,x)) if(k&1) ans=mul(ans,x);return ans;}
int inv(int x){ return powmod(x,mod-2);}
int mat[N][N],g[N][N],n;
char s[N];
int Rank()
{
	int work=25;
	map<int,int> cnt;
	while(work--)
	{
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
			{
				if(g[i][j])
				{
					int tmp=(((rand()<<10)|rand())%mod+mod)%mod;
					mat[i][j]=tmp;
					mat[j][i]=sub(0,tmp);
				}
				else mat[i][j]=mat[j][i]=0;
			}
		int r=0;
		for(int i=1;i<=n;i++)
		{
			bool ok=0;
			for(int j=r+1;j<=n;j++) if(mat[j][i])
			{
				for(int k=i;k<=n;k++) swap(mat[r+1][k],mat[j][k]);
				ok=1;
				break;
			}
			if(!ok) continue;
			r++;
			for(int j=r+1;j<=n;j++) if(mat[j][i])
			{
				int tmp=mul(mod-mat[j][i],inv(mat[r][i]));
				for(int k=i;k<=n;k++) mat[j][k]=add(mat[j][k],mul(mat[r][k],tmp));
			}
		}
		cnt[r]++;
	}
	int ans=0,c=0;
	for(auto it:cnt) if(c<=it.second) tie(ans,c)=it;
	return ans;
}
int main()
{
	srand(time(0));
	int t;scanf("%i",&t);
	while(t--)
	{
		int a,b;
		scanf("%i %i",&a,&b);
		n=a*2+b;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) g[i][j]=0;
		for(int i=1;i<=a;i++)
		{
			g[i][i+a]=1;
			scanf("%s",s+1);
			for(int j=1;j<=b;j++) if(s[j]=='1')
			{
				g[i][a*2+j]=1;
				g[i+a][a*2+j]=1;
			}
		}
		printf("%i\n",Rank()/2-a);
	}
	return 0;
}