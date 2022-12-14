#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int A,B,D;

int as[100100],bs[100100];

int l[100100];

int aid=-1,bid=-1;
double ans=-1;

int main()
{
	int N,M;
	scanf("%d%d%d%d",&N,&M,&A,&B);
	D=B-A;
	for(int i=0;i<N;i++) scanf("%d",as+i);
	for(int i=0;i<M;i++) scanf("%d",bs+i);
	for(int i=0;i<M;i++) scanf("%d",l+i);
	for(int i=0;i<M;i++)
	{
		double is=(double)bs[i]*((double)A/B);
		int id=lower_bound(as,as+N,is)-as;
		for(int j=max(0,id-1);j<=min(N-1,id+1);j++)
		{
			double tmp=sqrt((long long)A*A+(long long)as[j]*as[j]);
			tmp+=sqrt((long long)D*D+(long long)(bs[i]-as[j])*(bs[i]-as[j]));
			tmp+=l[i];
			if(ans==-1||ans>tmp)
			{
				ans=tmp;
				aid=j;
				bid=i;
			}
		}
	}
	printf("%d %d\n",aid+1,bid+1);
	return 0;
}