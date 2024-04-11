#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		scanf("%lld",&n);
		map<long long,long long> m;
		for(int i=0;i<n;i++) 
		{
			long long int t;
			scanf("%lld",&t);
			m.insert(make_pair(t,i));
		}
		long long int maxi=-1,mini=2e5+1;
		for(int x=1;x<=n;x++)
		{
			auto t=m.find(x);
			long long h=t->second;
			maxi=max(maxi,h);
			mini=min(mini,h);
			if(maxi-mini+1==x) cout<<'1';
			else cout<<'0';
 
		}	
		cout<<"\n";
	}
 
}