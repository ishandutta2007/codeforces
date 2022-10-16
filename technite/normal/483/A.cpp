#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int l,r;
	cin>>l>>r;
	if(l%2==0)
	{
		if((r-l)>=2)
		{
			cout<<l<<" "<<l+1<<" "<<l+2;
			return 0;
		}
	}
	else
	{
		if((r-l)>=3)
		{
			cout<<l+1<<" "<<l+2<<" "<<l+3;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}