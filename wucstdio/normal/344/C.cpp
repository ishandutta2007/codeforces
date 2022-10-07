#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll work(ll fz,ll fm)
{
	if(fm==0)return 0;
	return fz/fm+work(fm,fz%fm);
}
ll x,y;
int main()
{
	scanf("%I64d%I64d",&x,&y);
	printf("%I64d\n",work(x,y));
	return 0;
}