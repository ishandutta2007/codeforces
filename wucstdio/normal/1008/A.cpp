#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool judge(char c)
{
	if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='n')return 0;
	else return 1;
}
char s[1005];
int main()
{
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len-1;i++)
	{
		if(judge(s[i])&&judge(s[i+1])||judge(s[i])&&s[i+1]=='n')
		{
			printf("NO\n");
			return 0;
		}
	}
	if(judge(s[len-1]))
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	return 0;
}