#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
char s[105];
int main()
{
	scanf("%s",s+1);
	int len=strlen(s+1);
	for(int i=2;i<len;i++)
	{
		if(s[i-1]=='.'||s[i]=='.'||s[i+1]=='.')continue;
		if(s[i-1]!=s[i]&&s[i]!=s[i+1]&&s[i-1]!=s[i+1])
		{
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}