#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
__int64 n,m,a;
__int64 up(__int64 x,__int64 y)
{
	if (x%y==0)return x/y;
	return x/y+1;
}
int main()
{
	scanf("%I64d%I64d%I64d",&n,&m,&a);
	printf("%I64d",up(n,a)*up(m,a));
	return 0;
}