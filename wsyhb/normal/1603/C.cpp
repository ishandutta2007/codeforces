#include<bits/stdc++.h>
using namespace std;
#define div Div
inline int div(int a,int b)
{
	return (a+b-1)/b;
}
const int mod=998244353;
inline void add(int &a,int b)
{
	a=a+b-(a+b>=mod?mod:0);
}
const int max_n=1e5+5;
int a[max_n],b[max_n],id[max_n];
const int max_S=316+5;
int f[max_S][max_S],g[max_S][max_S],sf[max_S][max_S],l[max_S],r[max_S];
const int max_R=1e5+5;
int F[max_S][max_S<<1],G[max_S][max_S<<1],sF[max_S][max_S<<1];
typedef pair<int,int> P;
vector<P> val[max_S];
signed main()
{
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
//	int Start=clock();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int S=sqrt(n),C=div(n,S),R=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			R=max(R,a[i]);
			b[i]=a[i];
		}
		r[0]=0;
		for(int i=1;i<=C;++i)
		{
			l[i]=r[i-1]+1;
			r[i]=min(l[i]+S-1,n);
			for(int j=l[i];j<=r[i];++j)
				id[j]=i;
			for(int j=l[i];j<=r[i];++j)
			{
				for(int k=l[i];k<=j;++k)
					a[k]=b[k];
				sf[i][j-l[i]]=0;
				int cnt=0;
				for(int k=j-1;k>=l[i];--k)
				{
					if(a[k]>a[k+1])
					{
						int K=div(a[k],a[k+1]);
						add(cnt,K-1);
						a[k]/=K;
					}
					add(sf[i][j-l[i]],cnt);
				}
				f[i][j-l[i]]=cnt,g[i][j-l[i]]=a[l[i]];
			}
			val[i].clear();
			int tot=1;
			F[i][1]=f[i][r[i]-l[i]],G[i][1]=g[i][r[i]-l[i]],sF[i][1]=sf[i][r[i]-l[i]];
			val[i].push_back(P(R,1));
			int V=b[r[i]];
			for(int x=1,y;x<V;x=y+1)
			{
				if(V%x==0)
				{
					if(div(V,x+1)==V/x)
					{
						y=V/(V/(x+1));
						if(V%y==0)
							--y;
					}
					else
						y=x;
				}
				else
				{
					y=V/(V/x);
					if(V%y==0)
						--y;
				}
				for(int k=l[i];k<=r[i];++k)
					a[k]=b[k];
				a[r[i]+1]=x;
				int cnt=0,sum=0;
				for(int k=r[i];k>=l[i];--k)
				{
					if(a[k]>a[k+1])
					{
						int K=div(a[k],a[k+1]);
						add(cnt,K-1);
						a[k]/=K;
					}
					add(sum,cnt);
				}
				F[i][++tot]=cnt,G[i][tot]=a[l[i]],sF[i][tot]=sum;
				val[i].push_back(P(y,tot));
			}
			sort(val[i].begin(),val[i].end());
		}
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			int ID=id[i];
			ans=(ans+sf[ID][i-l[ID]]+1ll*f[ID][i-l[ID]]*r[ID-1])%mod;
			int now=g[ID][i-l[ID]];
			for(int j=ID-1;j>=1;--j)
			{
				int pos=lower_bound(val[j].begin(),val[j].end(),P(now,0))->second;
				ans=(ans+sF[j][pos]+1ll*F[j][pos]*r[j-1])%mod;
				now=G[j][pos];
			}
		}
		printf("%d\n",ans);
	}
//	int End=clock();
//	fprintf(stderr,"Time: %.3lf (s)\n",1.0*(End-Start)/CLOCKS_PER_SEC);
    return 0;
}
/*
1
8
7264 40515 28226 92776 35285 21709 75124 48163
---
117
*/