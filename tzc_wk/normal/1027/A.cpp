#include <bits/stdc++.h>
using namespace std;
bool palin(string s,int k)
{
	for(int i=0;i<(k+1)/2;i++)
	{
		//cout<<s[i]-s[k-1-i]<<endl;
		if(abs(s[i]-s[k-1-i])!=0&&abs(s[i]-s[k-1-i])!=2)	return false;
	}
	return true;
}
int main()
{
	int t;
	cin>>t;
	for(int e=0;e<t;e++)
	{
		string s;
		int k;
		cin>>k;
		cin>>s;
		if(palin(s,k))	cout<<"YES"<<endl;
		else	cout<<"NO"<<endl;
	}
	return 0;
}//