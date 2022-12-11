#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,k,i;
	cin>>n>>k;
	for(i=1;i<=k;i++)
	{
		if(n%10==0) n/=10;
		else n--;
	}
	cout<<n;
	return 0;
}