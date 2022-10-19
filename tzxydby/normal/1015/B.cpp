#include<bits/stdc++.h>
using namespace std;
int s1[30],s2[30];
vector<int>ans;
int main()
{
	int n,k,flag=1;
	string s,t;
	cin>>n>>s>>t;
	for(int i=0;i<n;i++)
		s1[s[i]-'a']++;
	for(int i=0;i<n;i++)
		s2[t[i]-'a']++;
	for(int i=0;i<26;i++)
		if(s1[i]!=s2[i])
			flag=0;
	if(!flag)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(s[j]==t[i])
			{
				k=j;
				break;
			}
		}
		while(k>i)
		{
			ans.push_back(k-1);
			swap(s[k-1],s[k]);
			k--;
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d ",ans[i]+1);
	return 0;
}