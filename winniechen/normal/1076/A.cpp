#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 200005
char s[N];
int n,p;
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		if(s[i+1]<s[i]){p=i;break;}
	if(!p)p=n;
	for(int i=1;i<=n;i++)if(i!=p)printf("%c",s[i]);puts("");
}