#include <stdio.h>
#include <cstring>
#include <vector>
using namespace std;
int Prev[26],Next[26];
bool vis[26],used[26],cnt[26];
const int N=100050;
char ch[N];
vector<char> sol;
int main()
{
	int n,m,i,j;
	bool ok=true;
	scanf("%i",&n);
	for(i=0;i<26;i++) Next[i]=-1,Prev[i]=-1;
	while(n--)
	{
		scanf("%s",&ch);
		m=strlen(ch);
		for(i=0;i<26;i++) cnt[i]=0;
		for(i=0;i<m;i++)
		{
			ch[i]-='a';
			if(cnt[ch[i]]) ok=false;
			cnt[ch[i]]=1;
			vis[ch[i]]=1;
		}
		for(i=0;i<m-1;i++)
		{
			if(Next[ch[i]]>-1 && Next[ch[i]]!=ch[i+1]) ok=false;
			if(Prev[ch[i+1]]>-1 && Prev[ch[i+1]]!=ch[i]) ok=false;
			Next[ch[i]]=ch[i+1];
			Prev[ch[i+1]]=ch[i];
		}
	}
	if(ok)
	{
		for(i=0;i<26;i++)
		{
			if(Prev[i]==-1 && vis[i])
			{
				j=i;
				while(j!=-1) sol.push_back(j+'a'),used[j]=1,j=Next[j];
			}
		}
		for(i=0;i<26;i++) if(vis[i] && !used[i]) ok=false;
		if(ok)
		{
			for(i=0;i<sol.size();i++) printf("%c",sol[i]);
			printf("\n");
		}
		else printf("NO\n");
	}
	else printf("NO\n");
	return 0;
}