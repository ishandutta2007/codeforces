#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[1000005],t[1000005];
int n,top;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	int i=1,j=n;
	while(i+2<j)
	{
		if(s[i]==s[j])t[++top]=s[i],i++,j--;
		else if(s[i]==s[j-1])t[++top]=s[i],i++,j-=2;
		else if(s[i+1]==s[j])t[++top]=s[i+1],i+=2,j--;
		else if(s[i+1]==s[j-1])t[++top]=s[i+1],i+=2,j-=2;
	}
	if(i+2<=j)
	{
		if(s[i]==s[j])
		  t[++top]=s[i],i++,j--;
		if(s[i+1]==s[j])
		  t[++top]=s[i+1],i+=2,j--;
		if(s[i]==s[j-1])
		  t[++top]=s[i],i++,j-=2;
	}
	if(i+1<=j)
	{
		if(s[i]==s[j])
		  t[++top]=s[i],i++,j--;
	}
	int len=top*2;
	if(i<=j)len++;
	if(len<n/2)
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}
	for(int i=1;i<=top;i++)putchar(t[i]);
	if(i<=j)putchar(s[i]);
	for(int i=top;i>=1;i--)putchar(t[i]);
	putchar('\n');
	return 0;
}