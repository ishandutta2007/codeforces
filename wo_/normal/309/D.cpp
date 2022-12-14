#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	long long ans=0;
	//for(int a=M+1;a<=N-M;++a)
	//for(int b=M+1;b<=N-M;b++)
	for(int b=M+1;b<=(N+1)/2;b++)
	{
		//for(int b=M+1;b<=(N+1)/2;++b)
		//for(int b=M+1;b<=N-M;++b)
		for(int a=M+1;a<=N-M;a++)
		{
			int coe=(b*2-1==N?3:6);
			int num=(2*b-a)*(N+1-b);
			int den=b+a;
			int x=(num-1)/den;
			if(x<=M) break;
			x=min(x,N-M);
			int tmp=max(x-M,0);
			ans+=tmp*coe;
		}
	}
	cout<<ans<<"\n";
}