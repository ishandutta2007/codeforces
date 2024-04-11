#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
char s[1005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		if(n==1)printf("YES\n");
		else if(n>=3)printf("NO\n");
		else if(s[1]==s[2])printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}