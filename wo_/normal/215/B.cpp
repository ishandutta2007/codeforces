#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int R=0;
int p1s[5050],p2s[5050];

double ans=0;

int A,B;

int main()
{
	int N,M,K;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		int r;
		scanf("%d",&r);
		R=max(R,r);
	}
	scanf("%d",&M);
	for(int i=0;i<M;i++) scanf("%d",p1s+i);
	scanf("%d",&K);
	for(int i=0;i<K;i++) scanf("%d",p2s+i);
	scanf("%d%d",&A,&B);
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<K;j++)
		{
			int p1=p1s[i],p2=p2s[j];
			double ra=(double)(A*p2)/(B*p1);
			ra+=1;
			double tmp=sqrt((R*R)/ra);
			ans=max(ans,tmp);
		}
	}
	printf("%.12f\n",ans);
	return 0;
}