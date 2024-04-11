#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll x,y,z;
int main()
{
	scanf("%I64d%I64d%I64d",&x,&y,&z);
	printf("%I64d ",(x+y)/z);
	if((x+y)/z==x/z+y/z)printf("0\n");
	else printf("%I64d\n",min((y/z+1)*z-y,(x/z+1)*z-x));
	return 0;
}