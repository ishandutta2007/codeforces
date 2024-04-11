#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
int t;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>s;
		if(s.size()>10)
			cout<<s[0]<<s.size()-2<<s[s.size()-1]<<endl;
		else
			cout<<s<<endl;
	}
	return 0;
}