#include<bits/stdc++.h>
using namespace std;
long long a,b,n;
int get(long long x)
{
	int s=0;
	while(x)
	  {
	  	s+=x%10;
	  	x/=10;
	  }
	return s;
}
int main()
{
	scanf("%lld",&n);
	if(n<10)
	  {
	  	printf("%lld",n);
	  	return 0;
	  }
	long long temp=9,tt=1;
	while(temp<=n)
	  {
	  	temp=temp*10+9;
	  	tt*=10;
	  }
	if(temp==n)
	  {
	  	printf("%d",get(temp));
	  	return 0;
	  }
	temp=(temp-9)/10;
	while(temp+tt<=n)
	  temp+=tt;
	printf("%d",get(temp)+get(n-temp));
	return 0;
}