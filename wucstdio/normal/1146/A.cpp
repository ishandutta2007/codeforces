#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[100005];
int n;
int main()
{
	scanf("%s",s+1);
	n=(int)strlen(s+1);
	int x=0;
	for(int i=1;i<=n;i++)
	  if(s[i]=='a')x++;
	printf("%d\n",min(x*2-1,n));
	return 0;
}