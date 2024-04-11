#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a,b,c,d;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a>b)swap(a,b);
	if(b>c)swap(b,c);
	if(c>d)swap(c,d);
	printf("%d %d %d\n",d-a,d-b,d-c);
	return 0;
}