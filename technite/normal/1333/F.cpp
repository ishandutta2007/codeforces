#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	long long n,coun=0;
	cin>>n;
	vector<long long> v(n+1,1);
    for (int p=2; p<=n; p++) 
    { 
        for (int i=2*p; i<=n; i += p) 
        {       
        	v[i] = p; 
        }
    }
	sort(v.begin(),v.end());
	for(int i=2;i<n+1;i++)
	{
		cout<<v[i]<<" ";
	}
	
	
}