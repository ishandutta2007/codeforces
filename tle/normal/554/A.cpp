#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;
bool rp[2300];
string str;
map<string,bool> sb;
int main()
{
	cin>>str;
	int sl=str.length(),ans=0;
	for(int i='a';i<='z';i++)
	{
		string ss;
		ss.push_back(i);
		for(int i=0;i<=sl;i++)
		{
			sb[str.substr(0,i)+ss+str.substr(i,sl-i)]=1;
		}
	}
	cout<<sb.size();
	return 0;
}