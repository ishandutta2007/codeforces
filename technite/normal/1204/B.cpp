#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,l,r;
	cin>>n>>l>>r;
	long long summin=0 ,summax=0;
	summin+=n-l+1;
	for(int i=0;i<l-1;i++)
	{
		summin+=pow(2,i+1);	
	}
	for(int i=0;i<r-1;i++)
	{
		summax+=pow(2,i);
	}
	summax+=(n-r+1)*pow(2,r-1);
	cout<<summin<<" "<<summax;
}