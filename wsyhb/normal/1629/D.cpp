#include<bits/stdc++.h>
using namespace std;
inline string con(char a,char b)
{
	string s;
	s.push_back(a);
	s.push_back(b);
	return s;
}
inline string con(char a,char b,char c)
{
	string s;
	s.push_back(a);
	s.push_back(b);
	s.push_back(c);
	return s;
}
const int max_n=1e5+5;
string s[max_n];
int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		bool flag=false;
		for(int i=1;i<=n;++i)
		{
			cin>>s[i];
			if(s[i].size()==1)
				flag=true;
			else if(s[i][0]==s[i].back())
				flag=true;
		}
		if(flag)
		{
			puts("YES");
			continue;
		}
		map<string,bool> vis;
		for(int i=n;i>=1;--i)
		{
			if(s[i].size()==2)
			{
				if(vis[con(s[i][1],s[i][0])])
				{
					flag=true;
					break;
				}
				for(char c='a';c<='z';++c)
				{
					if(vis[con(c,s[i][1],s[i][0])])
					{
						flag=true;
						break;
					}
				}
				if(flag)
					break;
			}
			else
			{
				if(vis[con(s[i][1],s[i][0])]||vis[con(s[i][2],s[i][1],s[i][0])])
				{
					flag=true;
					break;
				}
			}
			vis[s[i]]=true;
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}