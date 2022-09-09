#include <stdio.h>
#include <cstring>
const int N=105;
char word1[N],word2[N];
int main()
{
	int n,m,i;
	scanf("%s",&word1);
	scanf("%s",&word2);
	n=(unsigned) strlen(word1);
	m=(unsigned) strlen(word2);
	bool ok=true;
	if(n!=m) ok=false;
	else for(i=0;i<n;i++) if(word1[i]!=word2[n-i-1]) ok=false;
	if(!ok) printf("NO\n");
	else printf("YES\n");
	return 0;
}