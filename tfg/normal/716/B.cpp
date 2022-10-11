#include <string>
#include <iostream>
#include <queue>
#include <cstdio>

int freq[100];
int count_unk, count_tot;

int main()
{
	std::string str;
	std::cin >> str;
	count_unk=0;
	count_tot=0;
	for(int i=0;i<50;i++)
		freq[i]=0;
	std::queue<int> unk_where;
	bool ans=false;
	for(int i=0;i<str.size()&&!ans;i++)
	{
		if(i>=26)
		{
			if(str[i-26]=='?')
			{
				count_unk--;
				unk_where.pop();
			}
			else
			{
				freq[str[i-26]-'A']--;
				if(freq[str[i-26]-'A']==0)
				{
					count_tot--;
				}
			}
		}
		if(str[i]=='?')
		{
			count_unk++;
			unk_where.push(i);
		}
		else
		{
			if(freq[str[i]-'A']==0)
			{
				count_tot++;
			}
			freq[str[i]-'A']++;
		}
		if(count_tot+count_unk==26)
		{
			//printf("found ans ending on %i.\n",i);
			int j=0;
			while(!unk_where.empty())
			{
				while(freq[j]!=0)
				{
					j++;
				}
				str[unk_where.front()]='A'+j;
				unk_where.pop();
				j++;
			}
			ans=true;
		}
	}
	if(!ans) printf("-1\n");
	else
	{
		for(int i=0;i<str.size();i++)
		{
			printf("%c",str[i]=='?'?'A':str[i]);
		}
		printf("\n");
	}
}