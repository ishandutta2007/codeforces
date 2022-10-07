#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[500005];
int n;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int minn=200;
	for(int i=1;i<=n;i++)
	{
		minn=min(minn,(int)s[i]);
		if(minn==s[i])printf("Mike\n");
		else printf("Ann\n");
	}
	return 0;
}