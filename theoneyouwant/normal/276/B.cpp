#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
	string s;
	cin>>s;
	map <char, int> m;
	set <char> s1;
	for(int i=0;i<s.length();i++)
	{
	    if(s1.count(s[i])==0)
	    {
	        m[s[i]]=1;
	        s1.insert(s[i]);
	    }
	    else
	    {
	        m[s[i]]++;
	    }
	}
	int counter=0;
	for(set<char>::iterator it =  s1.begin();it!=s1.end();it++)
	{
	    if(m[(*it)]%2 ==1)
	    {
	        counter++;
	    }
	}
	if(counter==0)
	{
	    cout<<"First";
	}
	else if(counter%2==0)
	{
	    cout<<"Second";
	}
	else
	{
	    cout<<"First";
	}
	return 0;
}