#include<cstdio>
#include<iostream>

using namespace std;

int a[100100];

int main()
{
	int N,D;
	scanf("%d%d",&N,&D);
	for(int i=0;i<N;i++) scanf("%d",a+i);
	long long ans=0;
	int s=0,t=0;
	while(s<N)
	{
		while(t<N)
		{
			if(a[t]-a[s]>D) break;
			t++;
		}
		long long num=t-s;
		//ans+=(num*(num-1)*(num-2))/6;
		//ans+=max((num-2),0ll);
		ans+=((num-1)*(num-2))/2;
		s++;
	}
	cout<<ans<<"\n";
	return 0;
}