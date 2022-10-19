#include<bits/stdc++.h>
using namespace std;
char s[2000];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		int len=strlen(s);
		int flag=1;
		for(int i=0;i<len;i++)
			if(s[i]!=s[0])
				flag=0;
		if(flag)
		{
			puts("-1");
			continue;
		}
		sort(s,s+len);
		printf("%s\n",s);
	}
	return 0;
}