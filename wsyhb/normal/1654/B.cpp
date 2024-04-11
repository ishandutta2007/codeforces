#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
char s[max_n];
int id[26];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		memset(id,0,sizeof(id));
		for(int i=1;i<=n;++i)
			id[s[i]-'a']=i;
		for(int i=1;i<=n;++i)
		{
			if(id[s[i]-'a']==i)
			{
				printf("%s\n",s+i);
				break;
			}
		}
	}
	return 0;
}