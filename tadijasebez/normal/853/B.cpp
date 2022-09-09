#include <stdio.h>
#include <algorithm>
using namespace std;
const int M=1000050;
const int N=100050;
const long long inf=1000000ll*100000ll;
long long sol[M],best[N];
struct Flight
{
	int time,dest,cost;
	inline bool operator < (const Flight &b) const
	{
		return time<b.time;
	}
	Flight(){}
	Flight(int a, int b, int c)
	{
		time=a;
		dest=b;
		cost=c;
	}
} in[N],out[N];
long long min(long long a, long long b){ return a>b?b:a;}
int main()
{
	int n,m,i,k,d,u,v,c,j;
	scanf("%i %i %i",&n,&m,&k);
	int n1=0,n2=0;
	for(i=0;i<m;i++)
	{
		scanf("%i %i %i %i",&d,&u,&v,&c);
		if(u==0)
		{
			out[n2++]=Flight(d,v,c);
		}
		else
		{
			in[n1++]=Flight(d,u,c);
		}
	}
	sort(in,in+n1);
	sort(out,out+n2);
	for(i=1;i<=n;i++) best[i]=inf;
	long long tr=inf*n;
	j=n2-1;
	for(i=1000005;i>0;i--)
	{
		while(j>=0 && i==out[j].time)
		{
			if(best[out[j].dest]>out[j].cost)
			{
				tr-=best[out[j].dest];
				tr+=out[j].cost;
				best[out[j].dest]=out[j].cost;
			}
			j--;
		}
		sol[i]=tr;
	}
	for(i=1;i<=n;i++) best[i]=inf;
	tr=inf*n;
	j=0;
	long long ans=inf+1;
	for(i=1;i<=1000000-k+2;i++)
	{
		while(j<=n1 && i==in[j].time)
		{
			if(best[in[j].dest]>in[j].cost)
			{
				tr-=best[in[j].dest];
				tr+=in[j].cost;
				best[in[j].dest]=in[j].cost;
			}
			j++;
		}
		ans=min(ans,sol[i+k+1]+tr);
	}
	//for(i=1;i<=15;i++) printf("%i ",sol[i]);
	//printf("\n%lld\n",tr);
	printf("%lld\n",ans==inf+1?-1:ans);
	return 0;
}