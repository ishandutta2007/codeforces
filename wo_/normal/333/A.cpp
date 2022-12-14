#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
	long long N;
	cin>>N;
/*	long long ans=0;
	int fi=-1;
	while(N>0)
	{
		if(N%3!=0&&fi==-1) fi=N%3;
		ans+=(N%3);
		N/=3;
	}
	if(fi==1) cout<<ans<<"\n";
	else cout<<ans-1<<"\n";*/
	long long a=3;
	for(;;)
	{
		if(N%a!=0) break;
		a*=3;
	}
	cout<<(N/a)+1<<"\n";
	return 0;
}