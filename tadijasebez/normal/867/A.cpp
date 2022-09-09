#include <stdio.h>
const int N=105;
char word[N];
int s,t;
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",&word);
	for(i=1;i<n;i++)
	{
		if(word[i]=='F' && word[i-1]=='S') s++;
		if(word[i]=='S' && word[i-1]=='F') t++;
	}
	if(s>t) printf("YES\n");
	else printf("NO\n");
	return 0;
}