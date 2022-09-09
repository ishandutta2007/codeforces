#include <stdio.h>
#include <cstring>
const int N=1000050;
int fail[N],good[N];
char s[N];
int main()
{
	int n,i,j;
	scanf("%s",s);
	n=strlen(s);
	int p=0;
	for(i=1;i<n;i++)
	{
		while(p && s[i]!=s[p]) p=fail[p];
		if(s[i]==s[p]) p++;
		fail[i+1]=p;
		if(i<n-1) good[p]=1;
	}
	for(i=n;fail[i];i=fail[i])
	{
		if(good[fail[i]])
		{
			for(j=0;j<fail[i];j++) printf("%c",s[j]);
			printf("\n");
			return 0;
		}
	}
	printf("Just a legend\n");
	return 0;
}