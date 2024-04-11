#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int K,B,N,T;
	scanf("%d%d%d%d",&K,&B,&N,&T);
	long long num=1;
	int cnt=0;
	while(num<=T)
	{
		cnt++;
		num*=K;
		num+=B;
	}
	printf("%d\n",max(0,min(N,N-cnt+1)));
	return 0;
}