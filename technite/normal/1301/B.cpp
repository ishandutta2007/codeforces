#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>v(n+2);
		for(int i=1;i<=n;i++)
			cin>>v[i];
		int mi=1e9,ma=-1e9,k,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(v[i]!=-1&&(v[i-1]==-1||v[i+1]==-1))
				mi=min(mi,v[i]),ma=max(ma,v[i]);
		}
		k=(mi+ma)/2;
		if(v[1]==-1)v[1]=k;
		for(int i=2;i<=n;i++)
		{
			if(v[i]==-1) v[i]=k;
			ans=max(ans,abs(v[i]-v[i-1]));
		}
		cout<<ans<<" "<<k<<"\n";
	}
}