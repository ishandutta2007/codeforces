#include<cstdio>
#include<algorithm>

using namespace std;

int a[100100],b[100100];

int main()
{
	int N,X;
	scanf("%d%d",&N,&X);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	for(int i=0;i<N;i++) scanf("%d",b+i);
	sort(a,a+N);
	sort(b,b+N);
	int ub=N+1,lb=1;
	while(ub-lb>1)
	{
		int mid=(ub+lb)/2;
		int id=0;
		bool flg=true;
		for(int i=N-1;i>=N-mid;)
		{
			if(id>=N)
			{
				flg=false;
				break;
			}
			if(a[i]+b[id]>=X)
			{
				i--;id++;
			}
			else
			{
				id++;
			}
		}
		if(flg) lb=mid;
		else ub=mid;
	}
	printf("1 %d\n",lb);
	return 0;
}