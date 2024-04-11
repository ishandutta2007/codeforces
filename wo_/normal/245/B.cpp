#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

string str,ans;

int main()
{
	cin>>str;
	int id;
	if(str.substr(0,3)=="ftp")
	{
		id=3;
		ans+="ftp://";
	}
	else
	{
		id=4;
		ans+="http://";
	}
	int a=str.rfind("ru");
	ans+=str.substr(id,a-id);
	if(a==str.size()-2) ans+=".ru";
	else
	{
		ans+=".ru/";
		ans+=str.substr(a+2,100);
	}
	cout<<ans<<"\n";
	return 0;
}