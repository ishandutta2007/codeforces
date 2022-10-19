#include<bits/stdc++.h>
using namespace std;
bool is_v(char c)
{
	return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
}
int main()
{
	ios::sync_with_stdio(false);
	int n,k,t,tmp,cur=0;
	string s[4];
	cin>>n>>k;
	while(n--)
	{
		for(int i=0;i<4;i++)
		{
			cin>>s[i];
			t=0;
			for(int j=s[i].size()-1;j>=0;j--)
			{
				if(is_v(s[i][j]))
					t++;
				if(t==k)
				{
					s[i]=s[i].substr(j,s[i].size());
					break;
				}
			}
			if(t!=k)
			{
				puts("NO");
				return 0;
			}
		}
		if(s[0]==s[1]&&s[1]==s[2]&&s[2]==s[3])
			tmp=0;
		else if(s[0]==s[1]&&s[2]==s[3])	
			tmp=1;
		else if(s[0]==s[2]&&s[1]==s[3])
			tmp=2;
		else if(s[0]==s[3]&&s[1]==s[2])
			tmp=3;
		else
		{
			puts("NO");
			return 0;	
		}
		if(!tmp)
			continue;
		if(cur&&tmp!=cur)
		{
			puts("NO");
			return 0;
		}	
		cur=tmp;
	}
	if(cur==0)
		puts("aaaa");
	if(cur==1)
		puts("aabb");
	if(cur==2)
		puts("abab");
	if(cur==3)
		puts("abba");
	return 0;
}