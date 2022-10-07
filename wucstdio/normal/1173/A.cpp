#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,c;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	if(a>b+c)printf("+\n");
	else if(a+c<b)printf("-\n");
	else if(a==b&&c==0)printf("0\n");
	else printf("?\n");
	return 0;
}