#include<bits/stdc++.h>
using namespace std;
const int max_len=30+5;
char s[max_len],t[max_len];
int cnt[26];
bool mark[max_len];
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s%s",s+1,t+1);
		int ls=strlen(s+1),lt=strlen(t+1);
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=lt;++i)
			++cnt[t[i]-'A'];
		memset(mark,false,sizeof(mark));
		for(int k=0;k<26;++k)
			for(int i=ls;i>=1&&cnt[k]>0;--i)
			{
				if(s[i]-'A'==k)
				{
					mark[i]=true;
					--cnt[k];
				}
			}
		bool ok=true;
		for(int i=1,j=1;i<=lt;++i)
		{
			while(j<=ls&&!mark[j])
				++j;
			if(j>ls||s[j]!=t[i])
			{
				ok=false;
				break;
			}
			++j;
		}
		puts(ok?"YES":"NO");
	}
	return 0;
}