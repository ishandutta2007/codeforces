#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		s[i]=tolower(s[i]);
		if(!(s[i]=='e'||s[i]=='a'||s[i]=='y'||s[i]=='u'||s[i]=='o'||s[i]=='i'))
	cout<<"."<<s[i];
}
}