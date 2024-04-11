#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long a,b,c;
int main()
{
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	printf("%I64d\n",min(a,b)*2+2*c+(a==b?0:1));
	return 0;
}