#include <bits/stdc++.h>
using namespace std;
char ch[100005];
int t;
int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%s",ch);
		int len=strlen(ch);
		sort(ch,ch+len);
		int res=ch[0];
		for(int i=0;i<len;i++)
			if(ch[i]!=res)
			{
				for(int j=0;j<len;j++)
					printf("%c",ch[j]);
				printf("\n");
				goto A;
			}
		printf("-1\n");
		A:;
	}
	return 0;
}