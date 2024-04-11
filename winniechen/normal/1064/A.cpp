#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
// char s[1000005];int n;
// int main()
// {
// 	scanf("%d%s",&n,s+1);
// 	sort(s+1,s+n+1);
// 	printf("%s\n",s+1);
// }
int a,b,c;
int main()
{
	scanf("%d%d%d",&a,&b,&c);
	if(a>b)swap(a,b);if(b>c)swap(b,c);if(a>b)swap(a,b);
	if(a+b>c)return puts("0"),0;
	else return printf("%d\n",c-a-b+1),0;
}