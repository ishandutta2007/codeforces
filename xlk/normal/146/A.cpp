#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int n,len,sum1,sum2;
char str[100];
int vis[10];
inline bool check()
{
	for(int i=1;i<=n;i++)
		if(str[i]!='4'&&str[i]!='7')
		{
			printf("NO\n");
			return true;
		}
	return false;
}
int main()
{
	scanf("%d%s",&n,str+1);
	if(check()) return 0;
	for(int i=1;i<=n/2;i++)
	{
		sum1+=str[i]-'0';
		vis[str[i]-'0']++;
	}
	for(int i=n;i>=n/2+1;i--)
	{
		sum2+=str[i]-'0';
		vis[str[i]-'0']--;
	}
	if(sum1!=sum2) printf("NO\n");
	else
	{
		for(int i=0;i<9;i++)
			if(vis[i])
			{
				printf("NO\n");
				return 0;
			}
		printf("YES\n");
	}
	return 0;
}