#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int prime[N],a,b,k;
void get_prime()
{
	for(int i=2;i<N;i++)
	{
		if(prime[i])
			continue;
		for(int j=i+i;j<N;j+=i)
			prime[j]=1;
	}
}
int check(int l)
{
	for(int i=a;i<=b-l+1;i++)
		if(prime[i+l-1]-prime[i-1]<k)
			return 0;
	return 1;
}
int main()
{
	get_prime();
	for(int i=2;i<N;i++)
		prime[i]=!prime[i]+prime[i-1];
	scanf("%d%d%d",&a,&b,&k);
	int lb=0,ub=b-a+1;
	while(ub-lb>1)
	{
		int mid=(lb+ub)/2;
		if(check(mid))
			ub=mid;
		else
			lb=mid;
	}
	if(!check(ub))
		printf("%d\n",-1);
	else 
		printf("%d\n",ub);
	return 0;
}