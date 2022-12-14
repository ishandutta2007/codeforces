#include<cstdio>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<double,int> P;

P vs[50500];

int ps[50500],ls[50500];

double dp[50500];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d%d",ls+i,ps+i);
		double tmp=(double)ps[i]*ls[i]/(100-ps[i]);
		vs[i]=P(tmp,i);
	}
	sort(vs,vs+N);
	reverse(vs,vs+N);
	double res=0;
	dp[N-1]=0;
	for(int i=N-2;i>=0;i--)
	{
		dp[i]=dp[i+1]+(double)(100-ps[vs[i+1].second])/100;
		res+=dp[i]*ls[vs[i].second]*(double)(ps[vs[i].second])/100;
	}
	for(int i=0;i<N;i++) res+=ls[i];
	printf("%.12f\n",res);
	return 0;
}