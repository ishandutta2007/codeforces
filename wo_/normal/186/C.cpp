#include<cstdio>
#include<iostream>

using namespace std;

long long mod=1000000007;

long long npow(long long n)
{
	if(n==0) return 1;
	long long ans=1;
	ans*=npow(n/2);
	ans*=npow(n/2);
	ans%=mod;
	if(n%2==1) ans*=2;
	ans%=mod;
	return ans;
}

int main()
{
	long long N;
	//scanf("%d",&N);
	cin>>N;
	long long a=npow(N);
	long long ans2=(a*(a+1))%mod;
	if(ans2%2==0) ans2/=2;
	else ans2=(ans2+mod)/2;
	cout<<ans2<<"\n";
	return 0;
}