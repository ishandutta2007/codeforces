#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
LL n,m,x,y;
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&x,&y);
	printf("%I64d\n",min(n%m*y,(m-n%m)*x));
	return 0;
}