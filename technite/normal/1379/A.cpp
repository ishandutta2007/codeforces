#include<bits/stdc++.h>
using namespace std;
string req="abacaba";
bool check(int x,string&s)
{
	for(int i=x;i<=x+6;i++)
	{
		if(s[i]==req[i-x]) continue;
		if(s[i]!='?') return 0;
		if(s[i]=='?') s[i]=req[i-x];
	}
	int cnt=0;
	for(int i=0;i<s.size();i++)
	{
		if(i<s.size()-6){
		if(s.substr(i,7)==req) cnt++;}
		if(s[i]=='?') s[i]='d';
	}
	return cnt==1;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		bool flag=1;
		for(int i=0;i+6<(int)s.size();i++)
		{
			string temp=s;
			if(check(i,temp))
			{
				cout<<"YES"<<'\n';
				cout<<temp<<'\n';
				flag=0;
			}
			if(!flag) break;
		}
		if(flag)
		cout<<"NO"<<'\n';
	}
}