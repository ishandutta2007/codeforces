#include<bits/stdc++.h>
#define maxn 405
using namespace std;
int n;
string s[maxn];
map<string,int> mp;
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		string tmp;
		cin>>tmp;
		int len=tmp.length();
		s[i].clear();
		for(int j=0;j<len;++j)
		{
			if(tmp[j]=='u')
			{
				s[i].push_back('o');
				s[i].push_back('o');
			}
			else if(tmp[j]=='k')
			{
				bool ok=0;
				int k=j;
				for(;k<len;++k)
				{
					if(tmp[k]=='h')
					{
						ok=1;
						break;
					}
					else if(tmp[k]=='k')
					{
						continue;
					}
					else
					{
						break;
					}
				}
				if(ok)
				{
					s[i].push_back('h');
					j=k;
				}
				else s[i].push_back(tmp[j]);
			}
			else s[i].push_back(tmp[j]);
		}
		mp[s[i]]++;
	}
	int ans=0;
	for(auto p:mp)ans++;
	printf("%d\n",ans);
}