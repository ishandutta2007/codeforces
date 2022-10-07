#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n;
int main()
{
	scanf("%I64d",&n);
	while(n%3==0)n/=3;
	n/=3;
	printf("%I64d\n",n+1);
	return 0;
}