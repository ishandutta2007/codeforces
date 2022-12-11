#include<bits/stdc++.h>
using namespace std;
const int max_len=50+5;
char s[max_len];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		bool ok=true;
		for(int i=1;i<=len;++i)
		{
			int j=i;
			while(j+1<=len&&s[j+1]==s[i])
				++j;
			int cnt=j-i+1;
			if(cnt==1)
			{
				ok=false;
				break;
			}
			i=j;
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}