#include<bits/stdc++.h>
using namespace std;
const int max_len=2e5+5;
char s[max_len];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		if(s[1]!='A'||s[len]!='B')
		{
			puts("NO");
			continue;
		}
		int cntA=0,cntB=0;
		bool ok=true;
		for(int i=1;i<=len;++i)
		{
			if(s[i]=='A')
				++cntA;
			else
				++cntB;
			if(cntB>cntA)
			{
				ok=false;
				break;
			}
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}