#include<cstdio>

using namespace std;

int a[2200200];

long long get(int r,int N)
{
	long long res=0;
	int s=0,t=0;
	while(s<N)
	{
		while(t<N)
		{
			if(a[t]-a[s]<=r) t++;
			else break;
		}
		res+=t-s-1;
		s++;
	}
	return res;
}

int main()
{
	int N,L,T;
	scanf("%d%d%d",&N,&L,&T);
	for(int i=0;i<N;i++)
	{
		scanf("%d",a+i);
	}
	int r=(T*2)%L;
	long long tmp=get(r,N);
	for(int i=N;i<2*N;i++) a[i]=a[i-N]+L;
	long long cnt=get(r,2*N)-tmp;
	double ans=(long long)N*(N-1)/2;
	ans/=2;
	ans*=((T*2)/L);
	ans+=(double)cnt/4;
	printf("%.12f\n",ans);
	return 0;
}