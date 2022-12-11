#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
const int max_m=60+5;
char s[max_n][max_m],ans[max_m];
const int max_p=15+5;
int id[max_p];
const int max_S=1<<15|5;
int cnt[max_S],cnt_bits[max_S];
int main()
{
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	for(int S=1;S<(1<<p);++S)
		cnt_bits[S]=cnt_bits[S>>1]+(S&1);
	int Ans=0;
	for(int i=1;i<=m;++i)
		ans[i]='0';
	int T=50;
	srand(time(NULL));
	while(T--)
	{
		int key=(rand()<<15|rand())%n+1,tot=0;
		for(int i=1;i<=m;++i)
		{
			if(s[key][i]^'0')
				id[tot++]=i;
		}
		int Full=(1<<tot)-1;
		for(int i=1;i<=n;++i)
		{
			int mask=0;
			for(int j=0;j<tot;++j)
			{
				if(s[i][id[j]]^'0')
					mask|=1<<j;
			}
			++cnt[mask];
		}
		for(int i=0;i<tot;++i)
			for(int S=0;S<=Full;++S)
			{
				if(S>>i&1)
					cnt[S^(1<<i)]+=cnt[S];
			}
		for(int S=Full;S>=0;--S)
		{
			if((cnt[S]<<1)>=n&&cnt_bits[S]>Ans)
			{
				Ans=cnt_bits[S];
				for(int i=1;i<=m;++i)
					ans[i]='0';
				for(int i=0;i<tot;++i)
				{
					if(S>>i&1)
						ans[id[i]]='1';
				}
			}
			cnt[S]=0;
		}
	}
	printf("%s\n",ans+1);
	return 0;
}