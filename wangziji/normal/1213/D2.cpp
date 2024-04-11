#include <bits/stdc++.h>
#define int long long
using namespace std;
vector <int> v[200005];
signed main(int argc, char** argv) {
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin >> x;
		for(int j=0;j<=20;j++)
		{
			v[x].push_back(j);
			x/=2;
		}
	}
	for(int i=1;i<=200000;i++) sort(v[i].begin(),v[i].end());
	int ans=1e9;
	for(int i=1;i<=200000;i++)
	{
		if(v[i].size()<k) continue;
		int x=0;
		for(int j=0;j<k;j++) x+=v[i][j];
		ans=min(ans,x);
	 } 
	 cout << ans;
	return 0;
}