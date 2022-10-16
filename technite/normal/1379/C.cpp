#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<long long> a(m);
		vector<pair<long long,int>> b(m);
		map<int,long long> x;
		for(int i=0;i<m;i++) {cin>>a[i],cin>>b[i].first;b[i].second=i;x[i]=a[i];}
		sort(a.begin(),a.end(),greater<long long>());
		sort(b.begin(),b.end(),greater<pair<long long,long long>>());
		vector<long long> prefix(m,0);
		prefix[0]=a[0];
		for(int i=1;i<m;i++) prefix[i]=prefix[i-1]+a[i]; 
		long long ans=0;
	reverse(a.begin(),a.end());
		if(m>=n) ans=prefix[n-1];
		for(int i=0;i<m;i++)
		{
			long long temp=0;
			int val=b[i].first;
			int index=a.end()-upper_bound(a.begin(),a.end(),val);
			index--;
			index=min(index,n-1);
			if(index>=0) temp+=prefix[index];
			if(x[b[i].second]>b[i].first) temp+=b[i].first*(n-max(index+1,0));
			else
			{
				temp+=x[b[i].second];
				temp+=b[i].first*(n-max(index+1,0)-1);
			}
			ans=max(ans,temp);
		}
		cout<<ans<<'\n';
	}
}