#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t;
char s[10005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		int n=strlen(s);
		sort(s,s+n);
		if(s[0]==s[n-1])printf("-1\n");
		else printf("%s\n",s);
	}
	return 0;
}