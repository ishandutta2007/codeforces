#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		set<long long> s;
		while(n--) 
		{
			long long t;
			cin>>t;
			s.insert(t);
		}
		cout<<s.size()<<endl;
	}
}