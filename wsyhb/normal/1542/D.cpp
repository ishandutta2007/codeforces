#include<bits/stdc++.h>
using namespace std;
const int max_n=500+5;
int x[max_n],f[max_n][max_n];
const int mod=998244353;
inline void add(int &a,int b)
{
	a=a+b-(a+b>=mod?mod:0);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		static char op[4];
		scanf("%s",op);
		if(op[0]=='+')
			scanf("%d",x+i);
	}
	typedef pair<int,int> P;
	int ans=0;
	for(int k=1;k<=n;++k)
	{
		if(!x[k])
			continue;
		P now(x[k],k);
		f[0][0]=1;
		for(int i=1;i<=n;++i)
		{
			for(int j=0;j<=i;++j)
				f[i][j]=0;
			for(int j=0;j<=i-1;++j)
			{
				int v=f[i-1][j];
				if(v)
				{
					if(i!=k)
						add(f[i][j],v);
					if(x[i])
						add(f[i][j+(P(x[i],i)<now)],v);
					else
					{
						if(i<k)
							add(f[i][max(j-1,0)],v);
						else
						{
							assert(i>k);
							if(j)
								add(f[i][j-1],v);
						}
					}
				}
			}
		}
		int sum=0;
		for(int i=0;i<=n-1;++i)
			add(sum,f[n][i]);
		ans=(ans+1ll*sum*x[k])%mod;
	}
	printf("%d\n",ans);
	return 0;
}