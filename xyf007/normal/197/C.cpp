#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
std::string s,ans;
int main()
{
	std::cin>>s;
	int now=0,len=s.size();
	for(char i='z';i>='a';i--)
	{
		for(int j=now;j<len;j++)
		{
			if(s[j]==i)
			{
				ans+=i;
				now=j+1;
			}
		}
	}
	std::cout<<ans;
	return 0;
}