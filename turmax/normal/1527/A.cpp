#include <bits/stdc++.h> 

using namespace std;
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	int t;
	cin>>t;
	while(t--) 
	{
		int n;
		cin>>n;
		int u=1;
		while(u<=n) u*=2; 
		u/=2;
		u--;
		cout<<u<<'\n';
	}
	return 0;
}