#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int main()
{
	cin>>s1>>s2;
	sort(s1.begin(),s1.end());
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]>'0')
		{
			char c=s1[i];
			s1[i]=s1[0];
			s1[0]=c;
			break;
		}
	}
	if(s1==s2)	cout<<"OK";
	else cout<<"WRONG_ANSWER";
	return 0;
}