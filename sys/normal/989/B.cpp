#include <bits/stdc++.h>
using namespace std;
int n,p;
char ch[2005];
bool sul;
int main()
{
	scanf("%d%d",&n,&p);
	getchar(); 
	for(int i=0;i<n;i++)
		scanf("%c",&ch[i]);
	for(int i=p;i<n;i++)
	{
		if(ch[i]=='.')
		{
			sul=true;
			if(ch[i-p]=='.')
			{
				ch[i-p]='0';
				ch[i]='1';
			}
			else 
			ch[i]='0'+(ch[i-p]-'0')^1;
		}
		if(ch[i]!=ch[i-p])
		{
			sul=true;
			if(ch[i-p]=='.') ch[i-p]='0'+(ch[i]-'0')^1;
		}
	}
	if(sul)
	{
		for(int i=0;i<p;i++)
			if(ch[i]=='.') ch[i]='1';
		for(int i=0;i<n;i++)
			printf("%c",ch[i]);
	}
	else 
	{
		printf("No");
	}
	return 0;
}