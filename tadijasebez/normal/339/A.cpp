#include <stdio.h>
#include <cstring>
const int N=150;
char word[N];
int cnt[4];
int main()
{
	int n,i;
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	for(i=0;i<n;i+=2) cnt[word[i]-'0']++;
	for(i=0;i<cnt[1]+cnt[2]+cnt[3];i++)
	{
		if(i>0) printf("+");
		if(i<cnt[1]) printf("1");
		else if(i<cnt[1]+cnt[2]) printf("2");
		else printf("3");
	}
	return 0;
}