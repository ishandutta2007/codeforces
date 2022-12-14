#include<cstdio>
#include<deque>
#include<iostream>
#include<algorithm>

using namespace std;

deque<int> deq;

long long dp[100100];

int a[100100],b[100100];

long long f(int id,long long x)
{
	return x*b[id]+dp[id];
}

bool check(int i,int j,int k)
{
	long long aa=b[i],bb=dp[i];
	long long c=b[j],d=dp[j];
	long long e=b[k],f=dp[k];
	//return aa*f-bb*e<=c*f-bb*c+aa*d-d*e;
	double x=(double)(f-bb)/(aa-e);
	return x*c+d>=x*aa+bb;
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",a+i);
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d",b+i);
	}
	dp[0]=0;
	deq.push_back(0);
	for(int i=1;i<N;i++)
	{
		while(deq.size()>=2&&f(deq[0],a[i])>=f(deq[1],a[i])) deq.pop_front();
		dp[i]=f(deq[0],a[i]);
		while(deq.size()>=2&&check(deq[deq.size()-2],deq[deq.size()-1],i)) deq.pop_back();
		deq.push_back(i);
	}
	cout<<dp[N-1]<<"\n";
	return 0;
}