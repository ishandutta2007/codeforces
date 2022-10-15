#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
string s;
int main()
{
	cin>>s;
	int now=1,len=s.size(),temp=1,ans=0;
	while(now<len)
	{
		if(s[now]==s[now-1])
		{
			temp++;
		}
		else
		{
			if(!(temp&1))
			{
				ans++;
			}
			temp=1;
		}
		now++;
	}
	if(!(temp&1))
	{
		ans++;
	}
	printf("%d",ans);
	return 0;
}