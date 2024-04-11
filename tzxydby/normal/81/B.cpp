#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='.')
		{
			s[i]='@';
			s.erase(s.begin()+i+1);
			s.erase(s.begin()+i+1);
		}
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='@')
		{
			if(s[i-1]==' '||i==0)
				cout<<"...";
			else
				cout<<" ...";
		}
		else if(s[i]==',')
		{
			if(i==s.size()-1)
				cout<<",";
			else
			{
				cout<<", ";
				s[i]=' ';
			}
		}
		else if(s[i]==' ')
		{
			if(s[i-1]==' ')
				continue;
			if(s[i-1]==','||s[i+1]=='@'||(isdigit(s[i-1])&&isdigit(s[i+1])))
				cout<<' ';
			else
				s[i]=s[i-1];
		}
		else
			cout<<s[i];
	}
	return 0;
}
//