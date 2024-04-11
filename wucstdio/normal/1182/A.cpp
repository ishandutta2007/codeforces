#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	if(n&1)printf("0\n");
	else printf("%d\n",1<<(n/2));
	return 0;
}