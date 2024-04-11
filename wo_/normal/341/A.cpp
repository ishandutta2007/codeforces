#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

long long a[100100];
long long total[100100];

long long gcd(long long a,long long b)
{
	if(a<b) return gcd(b,a);
	if(b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	int N;
	cin>>N;
	a[0]=0;
	for(int i=1;i<=N;i++) cin>>a[i];
	sort(a,a+N+1);
	total[0]=0;
	for(int i=1;i<=N;i++) total[i]=total[i-1]+a[i];
	long long num=0;
	for(int i=1;i<=N;i++)
	{
		long long tmp=total[N]-total[i]-total[i-1]+a[i]*(2*i-N);
		num+=tmp;
	}
	long long d=gcd(num,N);
	cout<<num/d<<" "<<N/d<<"\n";
	return 0;
}