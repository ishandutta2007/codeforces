#include<bits/stdc++.h>
using namespace std;
long long n,k;
int check(long long x)
{
	long long add=x*(x+1)/2;
	long long eat=n-x;
	return (add-eat)>=k;
}
int main()
{
	cin>>n>>k;
	long long lb=1,ub=n;
	while(lb!=ub)
	{
		long long mid=(lb+ub)/2;
		if(check(mid))
			ub=mid;
		else
			lb=mid+1;
	}
	cout<<n-lb<<endl;
	return 0;
}