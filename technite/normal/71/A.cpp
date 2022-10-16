#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		if(s.size()>10)
		{
			cout<<s[0]<<s.size()-2<<s[s.size()-1]<<"\n";
		}
		else cout<<s<<endl;

	}
}