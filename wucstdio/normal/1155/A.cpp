#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char s[300005];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=2;i<=n;i++)
	{
		if(s[i]<s[i-1])
		{
			printf("YES\n");
			printf("%d %d\n",i-1,i);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}