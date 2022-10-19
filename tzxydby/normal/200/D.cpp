#include<bits/stdc++.h>
using namespace std;
const int N=1005;
vector<int>a[N],t; 
string names[N];
map<string,int>mp,dic;
int main()
{
	ios::sync_with_stdio(false);
	mp["int"]=1;
	mp["string"]=2;
	mp["double"]=3;
	mp["T"]=4;
	int n,m,k;
	string s,str;
	cin>>n;
	getline(cin,s);
	for(int i=1;i<=n;i++)
	{
		getline(cin,s);
		str="";
		for(int j=0;j<s.size();j++)
			if(s[j]!=' ')
				str+=s[j];
		int now=0;
		while(str[now]!='(')
			now++;
		names[i]=str.substr(4,now-4);
		while(str[now]!=')')
		{
			now++;
			s="";
			while(str[now]!=','&&str[now]!=')')
			{
				s+=str[now];
				now++;
			}
			a[i].push_back(mp[s]);
		}
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>s>>str;
		dic[str]=mp[s];
	}
	cin>>k;
	getline(cin,s);
	for(int i=1;i<=k;i++)
	{
		t.clear();
		getline(cin,s);
		str="";
		for(int j=0;j<s.size();j++)
			if(s[j]!=' ')
				str+=s[j];
		int now=0;
		while(str[now]!='(')
			now++;
		string name=str.substr(0,now);
		while(str[now]!=')')
		{
			now++;
			s="";
			while(str[now]!=','&&str[now]!=')')
			{
				s+=str[now];
				now++;
			}
			t.push_back(dic[s]);
		}
		int sum=0;
		for(int j=1;j<=n;j++)
		{
			int flag=1;
			if(a[j].size()!=t.size()||name!=names[j])
				continue;
			for(int v=0;v<t.size();v++)
			{
				if(a[j][v]!=t[v]&&a[j][v]!=4)
				{
					flag=0;
					break;
				}
			}
			sum+=flag;
		}
		cout<<sum<<endl; 
	} 
	return 0;
}