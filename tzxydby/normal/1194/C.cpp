#include<bits/stdc++.h>
using namespace std;
int need[30];
int main()
{	
	ios::sync_with_stdio(false);
	int q;
	cin>>q;
	while(q--)
	{
		memset(need,0,sizeof(need));
		string s,t,p;
		cin>>s>>t>>p;
		int i=0,j=0,flag=1;
		while(i<s.size())
		{
			while(j<t.size()&&t[j]!=s[i])
			{
				need[t[j]-'a']++;
				j++;
				if(j==t.size())
				{
					flag=0;
					break;
				} 
			}
			if(j==t.size())
				flag=0;
			if(!flag)
				break;
			i++; 
			j++;
		}
		if(!flag)
		{
			cout<<"NO"<<endl;
			continue;
		}
		while(1)
		{
			if(j>=t.size())
				break;
			need[t[j]-'a']++;
			j++;
			if(j>=t.size())
				break;
		}
		for(i=0;i<p.size();i++)
			need[p[i]-'a']--;
		for(int i=0;i<26;i++)
			if(need[i]>0)
				flag=0;
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}