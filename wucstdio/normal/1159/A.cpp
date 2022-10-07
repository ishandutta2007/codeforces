#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[100005];
int n;
int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	int now=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='-')now=max(0,now-1);
		else now++;
	}
	printf("%d\n",now);
	return 0;
}