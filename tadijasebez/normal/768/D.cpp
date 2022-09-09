#include <stdio.h>
#include <algorithm>
using namespace std;
#define ldb long double
const ldb eps=1e-7;
const int N=1050;
ldb dp[N][2];
int c,p=1;
ldb prob[N];
int id[N],sol[N],done;
bool comp(int i, int j){ return prob[i]<prob[j];}
int main()
{
	int x,n,q,i;
	scanf("%i %i",&n,&q);
	for(i=1;i<=q;i++)
	{
		scanf("%i",&x);
		id[i]=i;
		prob[i]=((ldb)x-eps)/2000;
		if(n==1) printf("1\n");
	}
	if(n==1) return 0;
	sort(id+1,id+1+q,comp);
	dp[1][p]=1;int day=1;
	while(done<q)
	{
		day++;
		for(i=1;i<=n;i++)
		{
			dp[i][c]=dp[i][p]*i/n+dp[i-1][p]*(n-i+1)/n;
		}
		while(done<q && prob[id[done+1]]<=dp[n][c])
		{
			sol[id[done+1]]=day;
			done++;
		}
		c^=1;p^=1;
	}
	for(i=1;i<=q;i++) printf("%i\n",sol[i]);
	return 0;
}