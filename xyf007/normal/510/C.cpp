#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
int n,ind[26];
std::string s[101];
std::vector<int>out[26];
bool vis[26];
void tuopu()
{
	int sum=0;
	std::vector<char>ans;
	while(sum<26)
	{
		bool f=0;
		for(int i=0;i<26;i++)
		{
			if(!ind[i]&&!vis[i])
			{
				ans.push_back(i+'a');
				vis[i]=1;
				sum++;
				f=1;
				for(std::vector<int>::iterator it=out[i].begin();it!=out[i].end();it++)
				{
					ind[*it]--;
				}
			}
		}
		if(!f&&sum<26)
		{
			printf("Impossible");
			exit(0);
		}
	}
	for(std::vector<char>::iterator it=ans.begin();it!=ans.end();it++)
	{
		printf("%c",*it);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		std::cin>>s[i];
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int len1=s[i].size(),len2=s[j].size();
			bool f=0;
			for(int k=0;k<len1&&k<len2;k++)
			{
				if(s[i][k]!=s[j][k])
				{
					ind[s[j][k]-'a']++;
					out[s[i][k]-'a'].push_back(s[j][k]-'a');
					f=1;
					break;
				}
			}
			if(!f&&len1>len2)
			{
				printf("Impossible");
				return 0;
			}
		}
	}
	tuopu();
	return 0;
}
//