#include<bits/stdc++.h>
using namespace std;
vector<unsigned long long>ans;
int main()
{
	ios::sync_with_stdio(false);
	unsigned long long n;
	cin>>n;
	ans.push_back(n*(n+1)/2);
	ans.push_back(1);
	unsigned long long tot=n*(n+1)/2;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i)
			continue;
		ans.push_back((2+n-i)*(n/i)/2);
		ans.push_back((2+n-(n/i))*n/(n/i)/2);
	}
	sort(ans.begin(),ans.end());
	ans.push_back(LLONG_MAX);
	for(int i=0;i<ans.size()-1;i++)
		if(ans[i]!=ans[i+1])
			cout<<ans[i]<<' '; 
	return 0;
}