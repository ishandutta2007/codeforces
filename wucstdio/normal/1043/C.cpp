#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char s[1005];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	s[n+1]='b';
	for(int i=1;i<=n;i++)
	{
		if(s[i]!=s[i+1])
		{
			printf("1 ");
			s[1]=s[i];
		}
		else printf("0 ");
	}
	printf("\n");
	return 0;
}