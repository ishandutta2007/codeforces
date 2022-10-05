#include <bits/stdc++.h>
using namespace std;
string str;
int cnt;
bool vis;
int main()
{
	cin>>str;
	int siz=str.size();
	for(int i=0;i<str.size();i++)
	{
		if(str[i]=='1'){vis=true;}
		if(str[i]=='0'&&vis){cnt++;}
	}
	if(cnt>=6)
		printf("yes");
	else printf("no");
	return 0;
}