#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,num;
char s[105];
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	  if(s[i]-'0'==8)num++;
	printf("%d\n",min(num,n/11));
	return 0;
}