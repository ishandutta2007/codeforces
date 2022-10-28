
#include <bits/stdc++.h>
using namespace std;

int main()
{	long long int rx=3000000000,rn=-3000000000,n;
	int c,d,flag=0;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>c;
		cin>>d;
		if (d==2)
		{
			if (flag==0)
			{
				flag=1;
			}
			if (rx>1899)
			{
				rx= 1899+c;
			}
			else {
				rx=rx+c;
				
			}
			rn = rn+c;
		}
		else
		{
			if (rn<1900)
			{
				rn=1900+c;
			}

			else{
				rn=rn+c;
			}
			if (flag)
			{
				rx=rx+c;
			}
			
		}
		
		if (rn>rx)
		{
			cout<<"Impossible";
			return 0;
		}
	}
	if (flag)
	{
		cout<<rx;
	}
	else{
		cout<<"Infinity";
	}
	return 0;
}