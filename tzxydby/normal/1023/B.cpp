#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,k;
	cin>>n>>k; 
	long long sum=(k-1)/2;
	if(k-n-1>0)
		sum-=k-n-1;
	if((k-1)/2-n-1>0)
		sum-=(k-1)/2-n-1;
	sum=max(sum,0LL);
	cout<<sum<<endl;
	return 0;
}