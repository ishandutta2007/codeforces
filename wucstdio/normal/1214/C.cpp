#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
char s[200005];
int top;
bool flag;
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(')top++;
		else
		{
			if(top)top--;
			else if(!flag)flag=1;
			else
			{
				printf("No\n");
				return 0;
			}
		}
	}
	if(flag)top--;
	if(top==0)printf("Yes\n");
	else printf("No\n");
	return 0;
}