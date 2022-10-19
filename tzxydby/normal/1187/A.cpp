#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,s,t,k;
		cin>>n>>s>>t;
		k=s+t-n;
		s-=k,t-=k;
		cout<<max(s,t)+1<<endl;
	}
	return 0;
}