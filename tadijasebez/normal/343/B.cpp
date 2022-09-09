#include <stdio.h>
#include <cstring>
const int N=100050;
char word[N],S[N];
int cnt;
int main()
{
	int n,i;
	scanf("%s",&word);
	n=(unsigned) strlen(word);
	for(i=0;i<n;i++)
	{
		if(cnt==0 || word[i]!=S[cnt]) S[++cnt]=word[i];
		else cnt--;
	}
	if(cnt==0) printf("Yes\n");
	else printf("No\n");
	return 0;
}