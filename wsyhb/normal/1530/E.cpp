#include<bits/stdc++.h>
using namespace std;
const int max_len=1e5+5;
char s[max_len];
int cnt[26];
inline void output(int x)
{
	assert(cnt[x]>0);
	--cnt[x];
	putchar(x+'a');
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		int len=strlen(s);
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<len;++i)
			++cnt[s[i]-'a'];
		int ch=-1;
		for(int i=0;i<26;++i)
		{
			if(cnt[i]==1)
			{
				ch=i;
				break;
			}
		}
		if(ch!=-1)
		{
			output(ch);
			assert(!cnt[ch]);
			for(int i=0;i<26;++i)
			{
				while(cnt[i])
					output(i);
			}
			putchar('\n');
			continue;
		}
		for(int i=0;i<26;++i)
		{
			if(cnt[i]==len)
			{
				ch=i;
				break;
			}
		}
		if(ch!=-1)
		{
			printf("%s\n",s);
			continue;
		}
		for(int i=0;i<26;++i)
		{
			if(cnt[i])
			{
				ch=i;
				break;
			}
		}
		assert(ch!=-1);
		if(cnt[ch]>=2)
		{
			if(len-cnt[ch]>=cnt[ch]-2)
			{
				output(ch);
				output(ch);
				int now=0;
				while(cnt[ch])
				{
					while(now<26&&(!cnt[now]||now==ch))
						++now;
					assert(now<26);
					output(now);
					output(ch);
				}
				for(int i=0;i<26;++i)
				{
					while(cnt[i])
						output(i);
				}
				putchar('\n');
				continue;
			}
		}
		int ch2=-1;
		for(int i=ch+1;i<26;++i)
		{
			if(cnt[i])
			{
				ch2=i;
				break;
			}
		}
		assert(ch2!=-1);
		if(cnt[ch]+cnt[ch2]<len)
		{
			int ch3=-1;
			for(int i=ch2+1;i<26;++i)
			{
				if(cnt[i])
				{
					ch3=i;
					break;
				}
			}
			assert(ch3!=-1);
			output(ch);
			output(ch2);
			while(cnt[ch])
				output(ch);
			output(ch3);
			for(int i=0;i<26;++i)
			{
				while(cnt[i])
					output(i);
			}
			putchar('\n');
		}
		else
		{
			output(ch);
			output(ch2);
			while(cnt[ch2])
				output(ch2);
			while(cnt[ch])
				output(ch);
			putchar('\n');
		}
	}
	return 0;
}