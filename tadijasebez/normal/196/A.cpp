#include <stdio.h>
#include <cstring>
const int N=100050;
char s[N],Max[N];
char max(char a, char b){ return a>b?a:b;}
int main()
{
	int n,i;
	scanf("%s",s+1);
	n=strlen(s+1);
	Max[n]=s[n];
	for(i=n-1;i>=1;i--) Max[i]=max(s[i],Max[i+1]);
	for(i=1;i<=n;i++) if(s[i]==Max[i]) printf("%c",s[i]);
	printf("\n");
	return 0;
}