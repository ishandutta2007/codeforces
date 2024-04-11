#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[200005],t[200005];
int n;
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int top=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]!=s[i+1]||top&1)
			t[++top]=s[i];
	}
	if(top&1)top--;
	printf("%d\n",n-top);
	for(int i=1;i<=top;i++)
	  putchar(t[i]);
	putchar('\n');
	return 0;
}