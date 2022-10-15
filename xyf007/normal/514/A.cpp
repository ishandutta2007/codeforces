#include<iostream>
#include<cstdio>
#include<string>
std::string s;
int main()
{
	std::cin>>s;
	if(s[0]>'4'&&s[0]!='9')
	{
		s[0]='9'-s[0]+'0';
	}
	for(int i=1;i<s.size();i++)
	{
		if(s[i]>'4')
		{
			s[i]='9'-s[i]+'0';
		}
	}
	std::cout<<s;
	return 0;
}
//gdg