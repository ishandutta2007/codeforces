#include <stdio.h>
#include <cstring>
char s[1000];
int main()
{
int n,i;
scanf("%s",s+1);
n=strlen(s+1);
bool ok=false;
for(i=2;i<n;i++)
{
if(s[i-1]!='.' && s[i]!='.' && s[i+1]!='.')
{
if(s[i-1]!=s[i] && s[i]!=s[i+1] && s[i-1]!=s[i+1]) ok=1;
}
}
if(ok) printf("Yes\n");
else printf("No\n");
return 0;
}