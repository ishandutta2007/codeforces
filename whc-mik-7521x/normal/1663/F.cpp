#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,t1="vampire"s,t2="buffy"s,t3="slayer",t4="the";
	cin>>s;
	if(s.size()==7)
	{
		string t="";
		for(int i=0;i<7;i++)
			t+=((char)('a'+(s[i]-'a'+t1[i]-'a')%26));
		cout<<t;
	}
	else if(s.size()==5)
	{
		string t="";
		for(int i=0;i<5;i++)
			t+=((char)('a'+(s[i]-'a'+t2[i]-'a')%26));
		cout<<t;
	}
	else if(s.size()==6)
	{
		string t="";
		for(int i=0;i<6;i++)
			t+=((char)('a'+(s[i]-'a'+t3[i]-'a')%26));
		cout<<t;
	}
	else if(s.size()==3)
	{
		string t="";
		for(int i=0;i<3;i++)
			t+=((char)('a'+(s[i]-'a'+t4[i]-'a')%26));
		cout<<t;
	}
	else puts("none");
	return 0;
}