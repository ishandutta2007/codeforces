#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
const int N=100050;
const int S=317;
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int nxt[N],cnt[N],a[N],lst[N];
int main()
{
	int n,m,i,j,k,t,sol;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=n;i;i--)
	{
		int L=i/S;
		if(i+a[i]>=(L+1)*S || i+a[i]>n)
		{
			cnt[i]=1;
			lst[i]=i;
			//nxt[i]=i+a[i];
		}
		else
		{
			cnt[i]=cnt[i+a[i]]+1;
			lst[i]=lst[i+a[i]];
			//nxt[i]=nxt[i+a[i]];
		}
	}
	while(m--)
	{
		//if(clock()>=0.9*CLOCKS_PER_SEC) return printf("%i\n",m),0;
		scanf("%i",&t);
		if(t)
		{
			scanf("%i",&j);
			sol=0;
			int ans;
			for(;j<=n;j=lst[j]+a[lst[j]]) sol+=cnt[j],ans=lst[j];
			printf("%i %i\n",ans,sol);
		}
		else
		{
			scanf("%i",&j);
			scanf("%i",&a[j]);
			int L=j/S;
			for(k=j;k>=S*L;k--)
			{
				if(k+a[k]>=(L+1)*S || k+a[k]>n)
				{
					cnt[k]=1;
					lst[k]=k;
					//nxt[k]=k+a[k];
				}
				else
				{
					cnt[k]=cnt[k+a[k]]+1;
					lst[k]=lst[k+a[k]];
					//nxt[k]=nxt[k+a[k]];
				}
			}
		}
	}
	return 0;
}