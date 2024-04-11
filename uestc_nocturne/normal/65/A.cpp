#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int a,b,c,d,e,f;
int main()
{
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	if(a*c*e<b*d*f)puts("Ron");
	else if(a==0&&b!=0&&d!=0)puts("Ron");
	else if(c==0&&d!=0)puts("Ron");
	else puts("Hermione");
}