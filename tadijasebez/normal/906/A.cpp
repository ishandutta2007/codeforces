#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
bool mark[26],possible[26],done;
char t;
string s;
int cnt,sol;
int main()
{
	int n,i;
	scanf("%i",&n);
	cnt=26;
	for(i=0;i<26;i++) possible[i]=1;
	while(n--)
	{
		scanf("\n%c",&t);
		cin >> s;
		for(i=0;i<26;i++) mark[i]=0;
		if(t=='!')
		{
			if(done) sol++;
			else
			{
				for(i=0;i<s.size();i++) mark[s[i]-'a']=1;
				for(i=0;i<26;i++) if(possible[i] && !mark[i]) possible[i]=0,cnt--;
				if(cnt==1) done=1;
			}
		}
		if(t=='.')
		{
			if(!done)
			{
				for(i=0;i<s.size();i++) mark[s[i]-'a']=1;
				for(i=0;i<26;i++) if(possible[i] && mark[i]) possible[i]=0,cnt--;
				if(cnt==1) done=1;
			}
		}
		if(t=='?')
		{
			if(done)
			{
				if(!possible[s[0]-'a']) sol++;
			}
			else
			{
				if(possible[s[0]-'a']) possible[s[0]-'a']=0,cnt--;
				if(cnt==1) done=1;
			}
		}
	}
	printf("%i\n",sol);
	return 0;
}