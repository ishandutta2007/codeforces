#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int k[400000];
int c[400000];
int main()
{
	std::ios::sync_with_stdio(0);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		int n,m;
		cin>>n>>m;
		for(int j=1;j<=n;j++) cin>>k[j];
		for(int j=1;j<=m;j++) cin>>c[j];
		long long ans;
		sort(k+1,k+n+1);
		long long s=0;
		for(int j=1;j<=n;j++) s+=c[k[j]];
		ans=s;
		for(int j=n;j>=max(1,n-m+1);j--)
		{
			s-=c[k[j]];
			s+=c[n-j+1];
			if(s<=ans) ans=s;
		}
		cout<<ans;
		if(i<t)
		cout<<endl; 
	}
	return 0; 
}