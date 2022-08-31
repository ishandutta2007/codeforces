#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
using namespace std;
map<string,int> ss;
int s;
string pp;
int main()
{
	cin>>s;
	while(s--)
	{
		cin>>pp;
		ss[pp]++;
	}
	#define mii map<string,int>::iterator
	int ans=0;
	for(mii i=ss.begin();i!=ss.end();i++) ans=max(ans,i->second);
	cout<<ans;
	return 0;
}