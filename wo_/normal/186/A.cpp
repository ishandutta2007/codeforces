#include<cstdio>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> v;

int main()
{
	string str,strr;
	cin>>str>>strr;
	if(str.size()!=strr.size())
	{
		printf("NO\n");
		return 0;
	}
	for(int i=0;i<str.size();i++)
	{
		if(str[i]!=strr[i])
		{
			v.push_back(i);
		}
	}
	if(v.size()!=2)
	{
		printf("NO\n");
		return 0;
	}
	int i=v[0],j=v[1];
	if(str[i]==strr[j]&&str[j]==strr[i])
	{
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}