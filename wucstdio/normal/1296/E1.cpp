#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char s[100005];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	for(int k=j+1;k<=n;k++)
	{
		if(s[i]>s[j]&&s[j]>s[k])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	int now1=0,now2=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]-'a'>=now1)printf("1"),now1=s[i]-'a';
		else printf("0"),now2=s[i]-'a';
	}
	printf("\n");
	return 0;
}