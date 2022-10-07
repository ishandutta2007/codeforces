#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,num;
char s[100005];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n-10;i++)
	  if(s[i]=='8')num++;
	if(num>(n-10)/2)printf("YES\n");
	else printf("NO\n");
	return 0;
}