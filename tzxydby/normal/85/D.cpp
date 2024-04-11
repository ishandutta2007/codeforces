#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		if(s=="add")
		{
			int x;
			cin>>x;
			a.insert(lower_bound(a.begin(),a.end(),x),x);
		}
		if(s=="del")
		{
			int x;
			cin>>x;
			a.erase(lower_bound(a.begin(),a.end(),x));
		}
		if(s=="sum")
		{
			long long x=0;
			for(int j=2;j<a.size();j+=5)
				x+=a[j];
			cout<<x<<endl;
		}
	}
	return 0;
}