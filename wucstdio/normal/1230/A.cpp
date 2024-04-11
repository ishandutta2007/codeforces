#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,c,d;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a+b==c+d||a+c==b+d||a+d==b+c)printf("YES\n");
	else if(a==b+c+d||b==a+c+d||c==a+b+d||d==a+b+c)printf("YES\n");
	else printf("NO\n");
	return 0;
}