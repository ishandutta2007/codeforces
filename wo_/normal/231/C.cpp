#include<cstdio>
#include<algorithm>

using namespace std;

int num[100100];

int main()
{
	int N,K;
	scanf("%d",&N);
	scanf("%d",&K);
	for(int i=0;i<N;i++) scanf("%d",num+i);
	sort(num,num+N);
	int s=0,t=1;
	int best=0,res=0;
	long long ope=0;
	while(s<N)
	{
		while(t<N&&ope<=K)
		{
			ope+=(long long)(num[t]-num[t-1])*(t-s);
			t++;
		}
		if(t==N)
		{
			if(ope<=K)
			{
				if(best<t-s)
				{
					best=t-s;
					res=num[t-1];
				}
				break;
			}
			//break;
		}
		//[s,t) is ng,[s,t-1) is ok
		if(best<t-1-s)
		{
			best=t-1-s;
			res=num[t-2];
		}
		ope-=(num[t-1]-num[s]);
		s++;
	}
	printf("%d %d\n",best,res);
	return 0;
}