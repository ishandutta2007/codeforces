#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,x,y,ans;
char s[200005];
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	scanf("%s",s+1);
	if(s[n-y]!='1')ans++;
	s[n-y]='0';
	for(int i=0;i<x;i++)
	  if(s[n-i]!='0')ans++;
	printf("%d\n",ans);
	return 0;
}