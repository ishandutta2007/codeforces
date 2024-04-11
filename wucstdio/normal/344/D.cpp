#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[100005];
int stack[100005],a[100005],len,top;
int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;i++)
	  a[i]=s[i]=='+';
	for(int i=1;i<=len;i++)
	{
		if(top>0&&stack[top]==a[i])top--;
		else stack[++top]=a[i];
	}
	if(top==0)printf("Yes\n");
	else printf("No\n");
	return 0;
}