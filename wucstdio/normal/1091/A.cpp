#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll a,b,c;
int main()
{
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	printf("%I64d\n",min(a+1,min(b,c-1))*3);
	return 0;
}