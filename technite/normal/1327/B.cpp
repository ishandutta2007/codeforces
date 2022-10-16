#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long arr[n+1]={0};
		for(int i=1;i<=n;i++) arr[i]=i;
			int o=0,b=0;
		for(long long i=0;i<n;i++)
		{
			long long g,f=0;
			cin>>g;
			for(long long j=1;j<=g;j++)
			{
				long long p;
				cin>>p;
				if(arr[p]==p)
				{
					if(f==0)
					arr[p]=0;
					f=1;
				}
			}
			if(f==0)
			{
				b=i+1;
			}
		}
		if(b!=0)
		{
                int l;
               // cout<<arr[4];
                
				for(int q=1;q<=n;q++)
				{
					if(arr[q]==q) {
					    l=q;
					    break;
					}
				}
				cout<<"IMPROVE";
				cout<<endl;
				cout<<b<<" "<<l;
				cout<<endl;
		}
		else if(b==0) cout<<"OPTIMAL"<<endl;
	}
}