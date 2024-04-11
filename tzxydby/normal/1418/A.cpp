#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		long long x,y,k,t,s=0;
		cin>>x>>y>>k;
		cout<<k+((k*(y+1)-1+x-1-1)/(x-1))<<endl;
	}
	return 0;
}