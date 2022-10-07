#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
char s[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&n,s+1);
		int i=1;
		while(i<=n&&s[i]!='8')i++;
		if(n-i+1>=11)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}