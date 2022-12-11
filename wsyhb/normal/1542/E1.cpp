#include<bits/stdc++.h>
using namespace std;
int n,mod;
const int max_n=50+5;
const int max_cnt=1225+5;
int cnt[max_n][max_cnt],pro[max_n];
inline void add(int &a,int b)
{
	a=a+b-(a+b>=mod?mod:0);
}
int main()
{
	scanf("%d%d",&n,&mod);
//	fprintf(stderr,"n=%d mod=%d\n",n,mod);
	cnt[1][0]=1%mod;
	for(int i=1;i<=n-1;++i)
		for(int j=0;j<=i*(i-1)/2;++j)
			for(int k=0;k<=i;++k)
				add(cnt[i+1][j+k],cnt[i][j]);
//	for(int i=1;i<=n;++i)
//		for(int j=0;j<=i*(i-1)/2;++j)
//			fprintf(stderr,"i=%d j=%d cnt[i][j]=%d\n",i,j,cnt[i][j]);
	pro[n+1]=1;
	for(int i=n;i>=1;--i)
	{
		pro[i]=1ll*pro[i+1]*i%mod;
//		fprintf(stderr,"i=%d pro[i]=%d\n",i,pro[i]);
	}
	int ans=0;
	for(int i=1;i<=n-1;++i)
	{
		int res1=0;
		for(int k=1;k<=i;++k)
		{
			int res2=0,sum=0;
			for(int j=0;j<=i*(i-1)/2;++j)
			{
				if(j-k>0)
					add(sum,cnt[i][j-k-1]);
				res2=(res2+1ll*sum*cnt[i][j])%mod;
			}
			res1=(res1+(i+1ll-k)*res2)%mod;
		}
		ans=(ans+1ll*pro[i+2]*res1)%mod;
	}
	printf("%d\n",ans);
    return 0;
}