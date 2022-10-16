#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n,c=0,a[3];
		cin>>n;
		for(long long int i=2;i*i<n;i++)
		{
			if(n%i==0) 
			{
				a[c]=i;
				c++;
				n/=i;
			}
			if(c==2) break;
		}
		if(c!=2)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			cout<<a[0]<<" "<<a[1]<<" "<<n<<endl;

		}
	}
}