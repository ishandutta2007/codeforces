#include<bits/stdc++.h>
using namespace std;
bool is(char a)
{
	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')
	{
		return true;
	}
	return false;
}
int main()
{
	string s,t;
	cin>>s>>t;
	int n=s.length();
	int m=t.length();
	if(n!=m)
	{
		cout<<"No\n";
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		if(is(s[i])!=is(t[i]))
		{
			cout<<"No\n";
			return 0;
		}
	}
	cout<<"Yes\n";
	return 0;
}