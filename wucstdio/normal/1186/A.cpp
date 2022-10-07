#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,c;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	if(a<=b&&a<=c)printf("Yes\n");
	else printf("No\n");
	return 0;
}