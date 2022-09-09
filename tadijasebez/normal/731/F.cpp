#include <stdio.h>
#define ll long long
const int N=200050;
const int M=2*N;
int C[M],X[N];
ll sum,ans,tmp;
bool Done[M];
ll max(ll a, ll b){ return a>b?a:b;}
int main()
{
	int n,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&X[i]),sum+=X[i],C[X[i]]++;
	for(i=1;i<=M;i++) C[i]+=C[i-1];
	for(i=1;i<=n;i++)
	{
		if(Done[X[i]]) continue;
		Done[X[i]]=1;
		if(X[i]==1){ ans=sum;break;}
		else
		{
			tmp=0;
			for(j=X[i];j<N;j+=X[i])
			{
				int c=C[j+X[i]-1]-C[j-1];
				tmp+=(ll)c*j;
			}
			ans=max(ans,tmp);
		}
	}
	printf("%lld\n",ans);
	return 0;
}