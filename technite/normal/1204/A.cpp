#include<iostream>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
#include<algorithm>
#include<math.h>
using namespace std;
int count(string s)
{
	int count=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0') count++;
	}
	return count;
}
int main()
{
	string s;
	cin>>s;
	
	
	int l=s.size();
	int t=count(s);
	
	
	if(l==1) cout<<'0';
	else if(t<l-1)
	{
		if(l%2==0)
		{
			cout<<(l/2);
		}
		else cout<<(l+1)/2;
	}
	else if(t==l-1)
	{
		if(l%2==0) cout<<l/2;
		else cout<<(l-1)/2;
	}
}