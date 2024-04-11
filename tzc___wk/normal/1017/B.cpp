#include <bits/stdc++.h>
#include <string>
using namespace std;
int main()
{
	long long type[4]={0};
	int n;
	string s,t;
	cin>>n;
	cin>>s>>t;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0'&&t[i]=='0')	type[0]++;
		else if(s[i]=='0'&&t[i]=='1')	type[1]++;
		else if(s[i]=='1'&&t[i]=='0')	type[2]++;
		else if(s[i]=='1'&&t[i]=='1')	type[3]++;
	}
	long long ans=type[0]*type[2]+type[3]*type[0]+type[1]*type[2];
	cout<<ans<<endl;
	return 0;
}