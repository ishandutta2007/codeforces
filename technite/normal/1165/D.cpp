#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<long long> a(n);
		for(int i =0;i<n;i++) cin>>a[i];
		sort(a.begin(),a.end());
		long long prod = a[0]*a[n-1];
		vector<long long> div; 
		for(long long i =2;i*i<=prod;++i)
		{
			if(prod%i==0)
			{
				div.push_back(i);
				if(i!=prod/i)
				div.push_back(prod/i);
			}
		}
		sort(div.begin(),div.end());
		if(div==a)
		{
			cout<<prod<<endl;
		}
		else
			cout<<"-1\n";
		
	}
}