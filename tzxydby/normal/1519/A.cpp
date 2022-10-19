#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b,c;
		cin>>a>>b>>c;
		if(a>b)
			swap(a,b);
		if(a*(c+1)>=b)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}