#include<bits/stdc++.h>
using namespace std;
const int N=105;
char s[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1),fl=1;
		for(int i=1;i<=n;i++)
			if(s[i]!=s[1])
				fl=0;
		if(fl)
		{
			for(int i=1;i<=n;i++)
				printf("%c",s[i]);
		}
		else
		{
			for(int i=1;i<=n;i++)
				printf("01");
		}
		puts("");
	}
	return 0;
}