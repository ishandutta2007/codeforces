#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int k,mx=0;
	cin>>k;
	int a[26],i;
	long sum=0;
	for(i=0;i<26;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	for(i=0;i<s.length();i++)
	{
		sum+=(i+1)*a[s[i]-'a'];
	}
	for(i=1;i<=k;i++)
	{
		sum+=mx*(s.length()+i);
	}
	cout<<sum;
	
}