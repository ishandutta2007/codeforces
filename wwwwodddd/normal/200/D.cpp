#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<sstream>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
string line()
{
	string s;
	static char buf[10000];
	gets(buf);
	return s=buf;
}
vector<string>split()
{
	string s=line();
	for(int i=0;i<s.size();i++)
		if(s[i]=='('||s[i]==')'||s[i]==',')
			s[i]=' ';
	istringstream in(s);
	vector<string>re;
	while(in>>s)
		re.push_back(s);
	return re;
}
vector<string>a[1010];
map<string,string>mp;
int ok(int i,vector<string>&v)
{
	if(v.size()!=a[i].size())
		return 0;
	if(v[0]!=a[i][0])
		return 0;
	for(int k=1;k<v.size();k++)
		if(a[i][k]!="T"&&a[i][k]!=mp[v[k]])
			return 0;
	return 1;
}
int INT()
{
	string s=line();
	return atoi(s.c_str());
}
int n,m,q;
int main()
{
	n=INT();
	for(int i=0;i<n;i++)
	{
		vector<string>v=split();
		for(int j=1;j<v.size();j++)
			a[i].push_back(v[j]);
	}
	m=INT();
	for(int i=0;i<m;i++)
	{
		vector<string>v=split();
		mp[v[1]]=v[0];
	}
	q=INT();
	for(int i=0;i<q;i++)
	{
		vector<string>v=split();
		int ans=0;
		for(int o=0;o<n;o++)
		{
			if(ok(o,v))
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}