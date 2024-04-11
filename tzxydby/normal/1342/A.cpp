#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b,x,y;
		cin>>x>>y>>a>>b;
		if(x>y)
			swap(x,y);
		b=min(b,2*a);
		cout<<b*x+a*(y-x)<<endl;
	}
	return 0;
}