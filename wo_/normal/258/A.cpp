#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='0')
		{
			string ans=str.substr(0,i);
			ans+=str.substr(i+1,100100);
			cout<<ans<<"\n";
			return 0;
		}
	}
	string ans=str.substr(1,100100);
	cout<<ans<<"\n";
	return 0;
}