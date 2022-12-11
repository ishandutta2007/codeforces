#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n];
const int max_k=100+5;
int b[max_k][max_n];
int C[max_n+max_k][max_k];
const int mod=1e9+7;
inline void add(int &a,int b)
{
	a+=b,a-=a>=mod?mod:0;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=0;i<=n+100;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=min(i,100);++j)
		{
			C[i][j]=C[i-1][j-1]+C[i-1][j];
			C[i][j]-=C[i][j]>=mod?mod:0;
		}
	}
	int K=0;
	while(m--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		K=max(K,k);
		add(b[k][l],1);
		add(b[k][r+1],mod-1);
		for(int i=0;i<=k-1;++i)
			add(b[i][r+1],mod-C[(k-i)+(r-l)][k-i]);
	}
	for(int i=K;i>=1;--i)
		for(int j=1;j<=n;++j)
		{
			add(b[i][j],b[i][j-1]);
			add(b[i-1][j],b[i][j]);
		}
	for(int i=1;i<=n;++i)
	{
		add(b[0][i],b[0][i-1]);
		add(a[i],b[0][i]);
		printf("%d%c",a[i],i<n?' ':'\n');
	}
	return 0;
}