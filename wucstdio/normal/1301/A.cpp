#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n;
char a[10005],b[10005],c[10005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%s%s",a+1,b+1,c+1);
		n=(int)strlen(a+1);
		bool flag=1;
		for(int i=1;i<=n;i++)
		{
			if(c[i]==a[i]||c[i]==b[i])continue;
			flag=0;
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}