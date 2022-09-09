#include <stdio.h>
#include <cstring>
const int N=200050;
char Get(char a, char b)
{
	int i;
	for(i=0;i<26;i++) if('a'+i!=a && 'a'+i!=b) return 'a'+i;
	return 0;
}
char s[N];
int main()
{
	int n,i;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]==s[i+1]) s[i+1]=Get(s[i],s[i+2]);
	}
	printf("%s\n",s+1);
	return 0;
}