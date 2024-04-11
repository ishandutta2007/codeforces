#include <stdio.h>
const int N=2050;
char s[N];
int main()
{
int n,p,i;
scanf("%i %i",&n,&p);
scanf("%s",s+1);
bool ok=0;
for(i=1;i+p<=n;i++)
{
if(s[i]=='.' && s[i+p]=='.')
{
s[i]='1';s[i+p]='0';ok=1;break;
}
else if(s[i]=='.')
{
s[i]='0'+((s[i+p]-'0')^1);ok=1;break;
}
else if(s[i+p]=='.')
{
s[i+p]='0'+((s[i]-'0')^1);ok=1;break;
}
else if(s[i]!=s[i+p]){ ok=1;break;}
}
if(!ok) return printf("No\n"),0;
for(i=1;i<=n;i++) if(s[i]=='.') s[i]='0';
printf("%s\n",s+1);
return 0;
}