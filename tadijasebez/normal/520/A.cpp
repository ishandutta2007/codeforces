#include <stdio.h>
#include <cstring>
char word[105];
bool vis[26];
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",&word);
	int sol=0;
	for(i=0;i<n;i++)
	{
		if(word[i]<'a') word[i]+='a'-'A';
		if(!vis[word[i]-'a']) sol++,vis[word[i]-'a']=true;
	}
	if(sol==26) printf("YES\n");
	else printf("NO\n");
	return 0;
}